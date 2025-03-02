main:
	g++ ./lib/can_bo.cpp ./lib/qlcb.cpp main.cpp -o main.exe
	./main.exe

# Uncomment if using dynamic linking
# main: qlcb_lib
# 	g++ main.cpp -Wl,-rpath=. -L. -lqlcb_lib -o main.exe
# 	del *.o
# 	del libqlcb_lib.a
# 	./main.exe

# can_bo:
# 	g++ -c ./lib/can_bo.cpp -fPIC

# qlcb:
# 	g++ -c ./lib/qlcb.cpp -fPIC

# qlcb_lib: can_bo qlcb
# 	g++ *.o -shared -o libqlcb_lib.dll -Wl,--out-implib,libqlcb_lib.a