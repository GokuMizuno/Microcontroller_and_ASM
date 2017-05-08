.global _start
_start:
	mov R7 #4
	MOV R0 #1
	MOV R1 #12
	LDR R1, =string
	SWI 0
	MOV R7, #1
.data
string:
.ascii "Hello Worldn"