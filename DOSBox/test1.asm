org 100h

start:
  mov [y], 0 ; итератор

  fwd:

  call decode_freq ; перевод номера ноты в частоту из массива и проигрывание её
  call decode_wait ; перевод номера ноты в паузу после ноты

  cmp [y],27 ; ограничение на количество нот
  je ext ; если в итераторе уже 27 - то конец программы
  inc [y] ; если же еще нет - то инкрементируем

  jmp fwd ; возвращаемся назад, для повторения цикла

  ext:
  ret


decode_freq:

  mov bx, freq	     ; конструкция необходимая для получения определенного элемента массива
  movzx ax, byte[y]  ; -||-
  add bx,ax	         ; -||-
  mov al, byte[bx]   ; -||-

  ; условия для массива частот

  cmp al,1
  je f1
  cmp al,2
  je f2
  cmp al,3
  je f3
  cmp al,4
  je f4
  cmp al,5
  je f5

  ; значение в al сравнивается с "индексом" "массива" и
  ; в соответствующей строке делает переход в соотвествующий блок кода
  ; аналог оператора switch

  ; если же ничего не получилось сравнить, сделаем частоту пустой, чтобы не воспроизвести ничего странного

  xor ebx, ebx
  jmp dfexit ; и прыгнем на выход

  f1:
    mov bx, [freq1]
    jmp dfexit
  f2:
    mov bx, [freq2]
    jmp dfexit
  f3:
    mov bx, [freq3]
    jmp dfexit
  f4:
    mov bx, [freq4]
    jmp dfexit
  f5:
    mov bx, [freq5]
    jmp dfexit

  ; каждый из вышеописанных блоков задает определенное значение частоты в зависимости
  ; от метки, по которой перешла программа

  dfexit:

  ; в итоге регистр bx содержит нужную частоту

  call beeper ; именно её и воспроизводим

  ret

decode_time:
  pusha

  mov bx, time
  movzx cx, byte[y]
  add bx,cx
  mov cl, byte[bx]

  call delay_count	 ; делает все тоже самое, что и decode_freq, только с другим массивом

  popa
  ret

decode_wait:
  pusha

  mov bx, wtime
  movzx cx, byte[y]
  add bx,cx
  mov cl, byte[bx]

  call delay_count	 ; делает все тоже самое, что и decode_freq, только с другим массивом

  popa
  ret


beeper:

  mov al, 182
  out 43h, al ; устанавливаем нужный, для воспроизведения, режим таймера = 0b10110110
  mov ax, bx
  out 42h, al ; устанавливаем частоту из регистра bx, сначала нижнюю часть
  mov al, ah
  out 42h, al ; а затем и верхнюю, предварительно поменяв al на ah

  in al, 61h
  or al, 03h ; 0x3 = 0b11
  out 61h, al  ; передаем частоту и включаем таймер

  call decode_time ; получаем задержку на произведение из другого массива

  in al, 61h
  and al, 0FCh ; 0xFC = 0b11111100
  out 61h, al ; выключаем звук

  ret

delay:
  pusha

  mov	  ah,86h
  xor	  cx,cx
  mov	  dx,57000 ; 57000 микросекунд = 57 миллисекунд
  int	  15h	   ; пауза в 57 ms, для удобного управления

  ; используется 86 функция 15 прерывания, 86H = wait

  popa

  ret

delay_count:
  pusha

  start_delay_count:

  dec cl ; декрементируем значение в регистре cl
  call delay ; вызываем функцию паузы
  cmp cl, 0 ; сравниваем с нулем

  je end_delay_count ; конец, если ноль
  jmp start_delay_count ; вернуться в начало, если нет, для повторения

  end_delay_count:
  popa
  ret

  freq1 dw 3619
  freq2 dw 3043
  freq3 dw 4063
  freq4 dw 4560
  freq5 dw 4831 	 ; перечень частот

  time db 10,2,2,2,3,15,15,10,2,2,2,3,15,15,10,2,2,2,3,15,15,10,2,2,2,3,15,15	   ; время проигрывания нот
  wtime db 2,3,5,5,2,2,2,2,3,5,5,2,2,2,2,3,5,5,2,2,2,2,3,5,5,2,2,2		   ; время между нотами
  freq db 1,1,2,1,3,4,5,1,1,2,1,3,4,5,1,1,2,1,3,4,5,1,1,2,1,3,4,5,1,1,2,1,3,4,5    ; частоты

  y rb 1