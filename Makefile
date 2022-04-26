out=p
src=./src/*.c
libpath= -I ./include/

cc:
	gcc $(src) -o $(out) $(libpath) -W -Wall -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_core -lavcall -lusb -std=c11 -g

cl:
	@rm $(out)
	@rm src/*~
	@rm include/*~
	@rm *~
