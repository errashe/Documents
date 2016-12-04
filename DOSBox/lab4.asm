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

	; floop:
 ;  inc ecx
 ;    add ebx, ebx
 ;  cmp ecx, 0x5f5e100
 ;  jb floop
  ;-----------------------------------------------------------------------------
  clr ecx
		testloop:
			inc ecx
			add ebx, ebx
			cmp ecx, 0x5f5e100
			jb testloop

    RDTSC
    mov dword[bp-200],edx
    mov dword[bp-204],eax
    clr ecx
    	floop:
		  inc ecx
		    ; add ebx, ebx
		  cmp ecx, 0x5f5e100
		  jb floop
    RDTSC
    sub eax,dword[bp-204]
    sbb edx,dword[bp-200]
    mov dword[bp-200],edx
    mov dword[bp-204],eax
  ;-----------------------------------------------------------------------------
  clr ecx
    	test2loop:
		  inc ecx
		    add ebx, ebx
		  cmp ecx, 0x5f5e100
		  jb test2loop
    RDTSC
    mov dword[bp-208],edx
    mov dword[bp-212],eax
    clr ecx
    	sloop:
		  inc ecx
		    add ebx, ebx
		  cmp ecx, 0x5f5e100
		  jb sloop
    RDTSC
    sub eax,dword[bp-212]
    sbb edx,dword[bp-208]
    sub eax,dword[bp-204]
    sbb edx,dword[bp-200]
    push eax
    mov eax,edx
    print_eax
    pop eax
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