#include   "avr/io.h"

.global Print_Hello

.set size_of_array, 14

Print_Hello:

    
; Setting baud rate 9600
    clr r0
    sts   UCSR0A, r0
    ldi   r24, 1<<RXEN0 | 1 << TXEN0  ; enable Rx & Tx
    sts   UCSR0B, r24
    ldi   r24, 1 << UCSZ00 | 1 << UCSZ01  ; asynchronous, no parity, 1 stop, 8 bits
    sts   UBRR0H, r0
    ldi   r24, 103
    sts   UBRR0L, r24


; loading address and size of array
    ldi XL, lo8(array)         ; r26
    ldi XH, hi8(array)         ; r27
    ld r16, X                  ; Load charactere pointed by X registers (r26/r27)
    ldi r24, size_of_array

boucle:
    lds   r17, UCSR0A
    sbrs  r17, UDRE0   ; test the data buffer if data can be transmitted
    rjmp  boucle
    sts   UDR0, r16     ; send data contained in r16
    dec   r24
    ld r16, X+        ; point to the next charactere
    brne Loop
    ret

/******************************************************/

wait:

ldi  R17, 0x53
LOOP0:  ldi  R18, 0xFB
LOOP1:  ldi  R19, 0xFF
LOOP2:  dec  R19
brne LOOP2
dec  R18
brne LOOP1
dec  R17
brne LOOP0

ret
