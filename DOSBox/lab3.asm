include 'dos_shell.inc'

use32
format MZ
entry code_seg:start

macro print_eax
{
	push ds
	set_seg ds, data_seg
	mov byte[temp_byte],224
	itoa_eax_dec temp_string,temp_byte,temp_word,temp_byte,temp
	print_string [temp_word]
	print_string control_line1
	pop ds
}

segment code_seg
	start:
	set_seg es, data_seg
	set_seg ds, ss

	push bp
	mov bp, sp
	sub sp, 232

	push eax, ebx

	RDTSC
	mov dword[bp-204], eax
	mov dword[bp-200], edx

	floop:
  inc ecx
    ; add ebx, ebx
  cmp ecx, 0x5f5e100
  jb floop

	RDTSC
	sub eax, dword[bp-204]
	sbb edx, dword[bp-200]

	mov dword[bp-204], eax
	mov dword[bp-200], edx

	pop ebx, eax


	push eax, ebx

RDTSC
	mov dword[bp-212], eax
	mov dword[bp-208], edx

	sloop:
  inc ecx
    ; add ebx, ebx
  cmp ecx, 0x5f5e100
  jb sloop

	RDTSC
	sub eax, dword[bp-212]
	sbb edx, dword[bp-208]

	mov dword[bp-212], eax
	mov dword[bp-208], edx

	pop ebx, eax

	mov eax, dword[bp-208]
	sub eax, dword[bp-200]
	print_eax

	mov eax, dword[bp-212]
	sub eax, dword[bp-204]
	print_eax

	mov sp, bp
	pop bp

	close_program


segment data_seg
	control_line1 db 0dh,0ah,'$'
  temp_byte rb 1
  temp rb 1
  temp_string rb 256
  temp_word rw 1