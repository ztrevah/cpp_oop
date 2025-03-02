main:
	g++ ./lib/thisinh.cpp ./lib/tuyensinh.cpp main.cpp -o main.exe
	./main.exe

# Uncomment if using dynamic linking
# main: qlts_lib
# 	g++ main.cpp -Wl,-rpath=. -L. -lqlts_lib -o main.exe
# 	del *.o
# 	del libqlts_lib.a
# 	./main.exe

# thisinh:
# 	g++ -c ./lib/thisinh.cpp -fPIC

# tuyensinh:
# 	g++ -c ./lib/tuyensinh.cpp -fPIC

# qlts_lib: thisinh tuyensinh
# 	g++ *.o -shared -o libqlts_lib.dll -Wl,--out-implib,libqlts_lib.a