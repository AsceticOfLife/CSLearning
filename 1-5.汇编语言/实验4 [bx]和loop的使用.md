# 实验4 [bx]和loop的使用

## 任务1

向内存0:200~0:23F依次传送数据0到63(3FH)

**代码：**

```
assume cs:codesg

codesg segment
	mov ax,0020H
	mov ds,ax
	mov cx,40H
	mov bx,0

s:	mov [bx],bl
	inc bx

	loop s

	mov ax,4c00H
	int 21H
codesg ends

end
```



![image-20230619221559914](.\lab-image\4-1-1.png)

执行完毕初始化工作：

![image-20230619221705459](.\lab-image\4-1-2.png)

<img src=".\lab-image\4-1-3.png" alt="image-20230619222732073" style="zoom:67%;" />

使用g执行执行到最后：

![image-20230619222815197](.\lab-image\4-1-4.png)

## 任务2

只用9条指令实现任务1，9条指令包含结束的两条指令。

上面就是9条指令。

## 任务3

下面程序的功能是将“mov ax,4c00H”之前的指令复制到内存0:200处，补全程序。

程序代码填充如下：（主要是补充目的段寄存器内容和需要复制的指令数也就是循环次数）

```
assume cs:codesg

codesg segment
	mov ax,cs
	mov ds,ax
	mov ax,0020h
	mov es,ax
	mov bx,0
	mov cx,17
	
s:	mov al,[bx]
	mov es:[bx],al
	inc bx
	loop s

	mov ax,4c00h
	int 21h
codesg ends

end
```

程序载入内存之后：

![image-20230620165938124](.\lab-image\4-3-1.png)

当前目标内存位置为空：

![image-20230620165316875](.\lab-image\4-3-2.png)

程序运行完毕之后目标内存位置就是机器指令：

![image-20230620170123217](.\lab-image\4-3-3.png)

















