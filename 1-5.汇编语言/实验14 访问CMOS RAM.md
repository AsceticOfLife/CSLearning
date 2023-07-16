# 实验14 访问CMOS RAM

## 任务1：显示时间

<img src=".\lab-image\14-1-1.png" alt="image-20230712195810978" style="zoom:67%;" />

代码逻辑：

1.使用循环次数为6读取CMOS RAM中的时间信息（转化成字符形式保存在栈中）

2.使用循环次数为3打印年月日

3.使用循环次数为3打印时分秒

```
assume cs:code

data segment
	db 0,2,4,7,8,9
data ends

stack segment
	db 16 dup(0)
stack ends

code segment
start:	mov ax,stack
	mov ss,ax
	mov sp,16
	
	mov ax,data
	mov ds,ax
	mov di,0
	
	;get data from CMOS RAM
	;and push into stack
	mov cx,6
move:	mov al,[di]
	out 70H,al
	in al,71H
	mov ah,al
	push cx
	mov cl,4
	shr ah,cl
	and al,00001111B
	add ah,30H
	add al,30H
	pop cx
	push ax
	inc di
	loop move

	;print y/m/d
	mov ax,0b800H
	mov es,ax
	mov si,160*12+30*2
	
	mov cx,3
print1:	pop ax
	mov es:[si],ah
	add si,2
	mov es:[si],al
	add si,2
	dec cx
	jcxz l
	mov byte ptr es:[si],5cH
l:	inc cx
	add si,2
	loop print1

	mov byte ptr es:[si],20H
	add si,2

	;print h:m:s
	mov cx,3
print2:	pop ax
	mov es:[si],ah
	add si,2
	mov es:[si],al
	add si,2
	dec cx
	jcxz l2
	mov byte ptr es:[si],3aH
l2:	inc cx
	add si,2
	loop print2
	
	mov ax,4c00H
	int 21H
code ends
end start
```

运行结果：

![image-20230712210502612](.\lab-image\14-1-2.png)











