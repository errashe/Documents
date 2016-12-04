include 'dos_shell.inc'

use32
format MZ
entry code_seg:start

macro out_channel number,control_word,divider
{
  push eax,ebx
  cli
  mov ebx,65536
  mov al,byte[control_word]
  out 43h,al
  sleep_iter ebx
  mov al,byte[divider]
  out number,al
  sleep_iter ebx
  mov al,byte[divider+1]
  out number,al
  sleep_iter ebx
  sti
  pop ebx,eax
}

macro in_channel number,control_word,divider
{
  push eax,ebx
  cli
  mov ebx,65536
  mov al,byte[control_word]
  out 43h,al
  sleep_iter ebx
  in al,number
  sleep_iter ebx
  mov byte[devider],al
  in al,number
  sleep_iter ebx
  mov byte[devider+1],al
  sti
  pop ebx,eax
}

macro on_sound
{
  push eax,ebx
  cli
  mov ebx,65536
  in al,61h
  sleep_iter ebx
  bts ax,0
  bts ax,1
  out 61h,al
  sleep_iter ebx
  sti
  pop ebx,eax
}

macro off_sound
{
  push eax,ebx
  cli
  mov ebx,65536
  in al,61h
  sleep_iter ebx
  btr ax,0
  btr ax,1
  out 61h,al
  sleep_iter ebx
  sti
  pop ebx,eax
}



macro decode_div nt,n,oct
{
  push ebx,ecx
  mov bx,nt
  movzx ax,n
  add bx,ax
  mov ax,word[bx]
  mov cl,oct
  shl ax,cl
  pop ecx,ebx
}

macro change_command first_str,first_size,size_value,second_string,second_size,result,met
{
  mov byte[first_size],size_value
  compare_string first_str,first_size,second_string,second_size,result
  cmp byte[result],1
  je met
}

macro wait_value x
{
    local beg
  beg:
    cmp byte[x],0
    je beg
}

macro print_eax
{
   mov byte[temp_byte],224
   itoa_eax_dec temp_string,temp_byte,temp_word,temp_byte,temp
   print_string [temp_word]
   print_string control_line1
}

;-------------------------------------------------------------------------------
segment data_seg
  command1 db 'exit$'
  command2 db 'clear$'
  command3 db 'sing$'
  command4 db 'ultr$'
  command5 db 'shotf$'
  control_line1 db 0dh,0ah,'$'
  control_line2 db 'Enter command:',0dh,0ah,'$'
  control_line3 db 'Incorrect command!',0dh,0ah,'$'
  notes dw 285,269,254,240,226,214,202,190,180,169,160,151,0
  mario_div db 8,24,8,24,8,24,0,24,8,24,14,24,14,24,0,24,14,24,8,24,18,24,22,24,20,18,24,14,24,8,24,14,24,18,24,10,24,14,24,8,24,0,24,4,24,22,24,0,24,14,24,8,24,18,24,22,24,20,18,24,14,24,8,24,14,24,18,24,10,24,14,24,8,24,0,24,4,24,22,24,14,24,12,24,10,24,6,24,8,24,16,24,18,24,0,24,18,24,0,24,4,24,14,24,12,24,10,24,6,24,8,24,0,24,0,24,0,24,14,24,12,24,10,24,6,24,8,24,16,24,18,24,0,24,18,24,0,24,4,24,6,24,4,24,0,24,0,24,0,24,0,24,0,24,4,24,8,24,0,24,18,24,14,24,0,24,0,24,0,24,0,24,4,24,8,24,18,24,14,24,0,24,0,24,0,24,0,24,4,24,8,24,0,24,18,24,14,24,8,24,8,24,8,24,0,24,8,24,14,24,14,24,14,24,0,24,8,24,14,24,0,24,8,24,14,24,8,24,16,24,0,24,6,24,16,24,0,24,6,24,16,24,6,24,20,24,4,24,10,24,20,24,4,24,10,24,20,24,20,24,20,24,20,24,0
  mario_oct db 4,0,4,0,4,0,4,0,4,0,4,0,5,0,4,0,5,0,5,0,5,0,5,0,5,5,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,4,0,5,0,5,0,5,0,5,0,5,5,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,4,0,4,0,4,0,4,0,4,0,5,0,5,0,4,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,3,0,3,0,3,0,4,0,4,0,4,0,4,0,4,0,5,0,5,0,4,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,5,0,5,0,4,0,4,0,4,0,3,0,3,0,3,0,3,0,5,0,4,0,4,0,4,0,3,0,3,0,3,0,3,0,5,0,4,0,4,0,4,0,3,0,3,0,3,0,3,0,3,0,3,0,2
  mario_counts db 4,4,4,12,4,12,4,4,4,12,4,28,4,28,12,12,12,12,12,12,12,4,4,12,8,4,12,4,6,4,6,4,6,4,12,4,4,4,12,4,12,4,4,4,4,4,20,12,12,12,12,12,12,12,4,4,12,8,4,12,4,6,4,6,4,6,4,12,4,4,4,12,4,12,4,4,4,4,4,36,4,4,4,4,4,4,4,12,4,12,4,4,4,4,4,12,4,4,4,4,4,20,4,4,4,4,4,4,4,12,4,12,4,12,4,4,4,44,4,4,4,4,4,4,4,12,4,12,4,4,4,4,4,12,4,4,4,4,4,20,12,12,12,12,12,52,4,4,4,12,4,12,4,4,4,12,8,2,8,2,8,2,4,28,4,4,4,12,4,12,4,4,4,4,4,28,4,12,4,20,4,4,4,12,4,12,4,4,4,12,8,2,8,2,8,2,4,28,4,4,4,12,4,12,4,4,4,12,4,28,4,28,4,5,4,5,4,5,4,5,4,5,4,5,4,23,4,23,4,5,4,5,4,5,4,5,4,5,4,5,4,23,4,23,4,5,4,5,4,5,4,5,4,5,4,5,4,23,4,5,4,5,4,5,27
  temp_string rb 256
  temp_addr rw 1
  needle rw 1
  flag rb 1
  plank rd 1
  counter rd 1
  temp_word rw 1
  temp_byte rb 1
  temp rb 1
  temp_dword rd 1
;-------------------------------------------------------------------------------
segment code_seg
  start:
    set_seg ds,data_seg
    set_seg es,data_seg
    push bp
    mov bp,sp
    sub sp,8
  begin:
    print_string control_line2
    mov word[ss:bp-2],253
    input_string temp_string,ss:bp-2,temp_addr,ss:bp-2
    print_string control_line1

    change_command command1,ss:bp-6,5,[temp_addr],ss:bp-2,ss:bp-4,exit
    change_command command2,ss:bp-6,6,[temp_addr],ss:bp-2,ss:bp-4,clear
    change_command command3,ss:bp-6,5,[temp_addr],ss:bp-2,ss:bp-4,sing
    change_command command4,ss:bp-6,5,[temp_addr],ss:bp-2,ss:bp-4,ultr
    change_command command5,ss:bp-6,6,[temp_addr],ss:bp-2,ss:bp-4,shotf

    print_string control_line3
    jmp begin

  exit:
    mov sp,bp
    pop bp
    close_program

  clear:
    clear_screen
    jmp begin

  sing:
    call lab1:start_sing
    jmp begin

  ultr:
    call lab1:ultra
    jmp begin

  shotf:
    call lab2:get_operation_time_var1
    jmp begin
;-------------------------------------------------------------------------------
segment lab1
  start_sing:
    push bp
    mov bp,sp
    sub sp,12
    push ds
    set_seg ds,data_seg
    mov word[needle],0
    mov byte[flag],0
    set_seg ds,ss
    mov byte[bp-2],00110110b
    mov word[bp-4],15000
    out_channel 40h,bp-2,bp-4
    set_IRQ0_handler gramophone,bp-8,bp-12
    get_char
    reset_IRQ0_handler bp-8,bp-12
    off_sound
    pop ds
    mov sp,bp
    pop bp
    retf

  gramophone:
    push eax,ebx,edx,ds,es,esi
    set_seg ds,data_seg
    set_seg es,data_seg
    cmp byte[flag],0
    je gr_up
    mov eax,dword[counter]
    cmp eax,[plank]
    je gr_re
    inc dword[counter]
    jmp gr_over
  gr_up:
    cmp word[needle],265
    je gr_anew
    mov byte[flag],1
    mov si,word[needle]
    mov dl,[mario_div+si]
    mov dh,[mario_oct+si]
    decode_div notes,dl,dh
    cmp ax,0
    je gr_next
    mov word[temp_word],ax
    mov byte[temp_byte],10110110b
    out_channel 42h,temp_byte,temp_word
    on_sound
  gr_next:
    mov dword[counter],0
    movzx eax,byte[mario_counts+si]
    mov dword[plank],eax
    inc word[needle]
  gr_over:
    int 0FFh
    mov al,20h
    out 20h,al
    pop esi,es,ds,edx,ebx,eax
    iret

  gr_anew:
    mov word[needle],0
    jmp gr_over
  gr_re:
    off_sound
    mov byte[flag],0
    jmp gr_up

  ultra:
    push bp
    mov bp,sp
    sub sp,12
    push ds
    set_seg ds,data_seg
    mov byte[flag],0
    set_seg ds,ss
    mov byte[bp-2],00110110b
    mov word[bp-4],301
    out_channel 40h,bp-2,bp-4
    mov byte[bp-2],10110110b
    mov word[bp-4],50
    out_channel 42h,bp-2,bp-4
    set_IRQ0_handler ultr_sound,bp-8,bp-12
    get_char
    reset_IRQ0_handler bp-8,bp-12
    off_sound
    pop ds
    mov sp,bp
    pop bp
    retf

  ultr_sound:
    push eax,ebx,edx,ds,es,esi
    set_seg ds,data_seg
    set_seg es,data_seg
    cmp byte[flag],0
    je ul_on
    mov byte[flag],0
    off_sound
    jmp ul_exit
  ul_on:
    mov byte[flag],1
    on_sound
  ul_exit:
    int 0FFh
    mov al,20h
    out 20h,al
    pop esi,es,ds,edx,ebx,eax
    iret
;-------------------------------------------------------------------------------
segment lab2
  get_operation_time_var1:
    push bp
    mov bp,sp
    sub sp,228
    push ds,eax
    set_seg ds,data_seg
    mov byte[flag],0
    mov dword[counter],0
    mov dword[temp_dword],0
    set_seg ds,ss
    mov byte[bp-2],00110110b
    mov word[bp-4],0
    out_channel 40h,bp-2,bp-4
    push 1,ot_with
    set_IRQ0_handler time_counter,bp-8,bp-12
    set_seg ds,data_seg
    wait_value ds:flag
    set_seg ds,ss
    call dive
    reset_IRQ0_handler bp-8,bp-12
    set_seg ds,data_seg
    mov byte[flag],0
    mov eax,dword[counter]
    mov dword[plank],eax
    mov dword[counter],0
    set_seg ds,ss
    push 1,ot_without
    set_IRQ0_handler time_counter,bp-8,bp-12
    set_seg ds,data_seg
    wait_value ds:flag
    set_seg ds,ss
    call dive
    reset_IRQ0_handler bp-8,bp-12
    set_seg ds,data_seg
    mov eax,dword[plank]
    mov dword[bp-204],eax
    print_eax
    mov eax,dword[counter]
    mov dword[bp-208],eax
    print_eax
    set_seg ds,ss
    mov dword[bp-212],55
    mov dword[bp-216],1111111111111101b
    mov dword[bp-220],00000000000000101111111111111111b
    mov dword[bp-224],0
    mov dword[bp-228],111011100110101100101000000000b
    ;11111111111111100000000000000001
    ;---------------------------------------------------------------------------
    fnsave [bp-200]
    finit
    fild qword[bp-228]
    fild qword[bp-220]
    fild dword[bp-212]
    fild dword[bp-208]
    fild dword[bp-204]
    fsub st0,st1
    fmul st0,st2
    fdiv st0,st3
    fmul st0,st4
    fist dword[bp-212]
    fwait
    frstor [bp-200]
    ;---------------------------------------------------------------------------
    mov eax,dword[bp-212]
    set_seg ds,data_seg
    print_eax
    pop eax,ds
    mov sp,bp
    pop bp
    retf

  dive:
    push bp
    mov bp,sp
    push eax,ecx
    mov ax,word[bp+6]
    cmp ax,0
    je dive_do
    dec ax
    mov cx,0
  dive_cycle:
    push ax,word[bp+4]
    call dive
    long_loop dive_cycle
    jmp dive_end
  dive_do:
    mov cx,0
  doing:
    call word[bp+4]
    ;push ax
    ;set_seg ds,data_seg
    ;mov eax,dword[temp_dword]
    ;inc dword[temp_dword]
    ;print_eax
    ;set_seg ds,ss
    ;pop ax
    loop doing
  dive_end:
    pop ecx,eax
    pop bp
    ret 4


  ot_with:
    push ax,bx
    add ax,bx
    pop bx,ax
    ret

  ot_without:
    push ax,bx
    pop bx,ax
    ret

  time_counter:
    push eax,ebx,edx,ds,es,esi
    set_seg ds,data_seg
    set_seg es,data_seg
    mov byte[flag],1
    inc dword[counter]
    int 0FFh
    mov al,20h
    out 20h,al
    pop esi,es,ds,edx,ebx,eax
    iret
;-------------------------------------------------------------------------------