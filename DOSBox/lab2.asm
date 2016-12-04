include 'dos_shell.inc'

use32
format MZ
entry code_seg:start

macro print_eax
{
   mov byte[temp_byte],224
   itoa_eax_dec temp_string,temp_byte,temp_word,temp_byte,temp
   print_string [temp_word]
   print_string control_line1
}

macro set_IRQ0_handler handler,first_vector,second_vector
{
  push eax,es
  cli
  clr eax
  mov es,ax
  mov eax,[es:8*4]
  mov dword[first_vector],eax
  mov eax,[es:255*4]
  mov dword[second_vector],eax
  mov eax,dword[first_vector]
  mov [es:255*4],eax
  mov ax,handler
  mov [es:8*4],ax
  mov [es:8*4+2],cs
  sti
  pop es,eax
}

macro reset_IRQ0_handler first_vector,second_vector
{
  push eax,es
  cli
  clr eax
  mov es,ax
  mov eax,dword[second_vector]
  mov [es:255*4],eax
  mov eax,dword[first_vector]
  mov [es:8*4],eax
  sti
  pop es,eax
}

segment code_seg
	start:
    set_seg ds,data_seg
    set_seg es,data_seg

    call first_count
    call second_count

    finit
    fild dword[bp-304]
    fild dword[bp-300]
    fsub st0, st1
    ; fdiv st0, st1
    fist dword[bp-300]
    fwait

    mov eax,dword[bp-300]
    set_seg ds, data_seg
    print_eax

    close_program


first_count:
  mov ecx, 0

  set_IRQ0_handler time_counter,bp-8,bp-12

  mov [counter], 0

  floop:
  inc ecx
    add ebx, ebx
  cmp ecx, 0x5f5e100
  jb floop

  ; mov eax, [counter]
  ; print_eax

  reset_IRQ0_handler bp-8,bp-12

  mov eax, [counter]
  mov dword[bp-204], eax
  mov dword[bp-208], 55
  mov dword[bp-212], 100

  finit
  fild dword[bp-212]
  fild dword[bp-208]
  fild dword[bp-204]
  fmul st0, st1
  fdiv st0, st2
  fist dword[bp-300]
  fwait

  mov eax,dword[bp-300]
  set_seg ds, data_seg
  print_eax
  ret

second_count:
  mov ecx, 0

  set_IRQ0_handler time_counter,bp-8,bp-12

  mov [counter], 0

  sloop:
  inc ecx
    ; add ebx, ebx
  cmp ecx, 0x5f5e100
  jb sloop

  ; mov eax, [counter]
  ; print_eax

  reset_IRQ0_handler bp-8,bp-12

  mov eax, [counter]
  mov dword[bp-204], eax
  mov dword[bp-208], 55
  mov dword[bp-212], 100

  finit
  fild dword[bp-212]
  fild dword[bp-208]
  fild dword[bp-204]
  fmul st0, st1
  fdiv st0, st2
  fist dword[bp-304]
  fwait

  mov eax,dword[bp-304]
  set_seg ds, data_seg
  print_eax
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

segment data_seg
	control_line1 db 0dh,0ah,'$'
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

  y rw 1