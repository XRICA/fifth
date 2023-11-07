SRC =  $(wildcard *.c)
OBJ =  $(patsubst %.c, %.o, $(SRC))

#更改run的名字为自己需要生成的可执行文件名
TARGET = exa

.PHONY:clean

$(TARGET):$(OBJ)
	gcc $< -o $@ -lm
$(OBJ):$(SRC)
	gcc -c $< -o $@

#$(TARGET):$(SRC)
#	gcc $< -o $@
clean:
	rm -rf $(TARGET)
	rm -rf $(OBJ)
