all: password.o main.o shake.o xof.o keccakcore.o
	g++ -std=c++11 -o bin/bin build/password.o build/main.o build/shake.o build/keccakcore.o build/xof.o

password.o: src/password.cpp
	g++ -std=c++11 -c src/password.cpp -o build/password.o -Iinclude/ -Iarduinolibs/libraries/Crypto
	
main.o: src/main.cpp
	g++ -std=c++11 -c src/main.cpp -o build/main.o -Iinclude/

shake.o: arduinolibs/libraries/Crypto/SHAKE.cpp
	g++ -std=c++11 -c arduinolibs/libraries/Crypto/SHAKE.cpp -Iarduinolibs/libraries/Crypto -o build/shake.o
	 
xof.o: arduinolibs/libraries/Crypto/XOF.cpp
	g++ -std=c++11 -c arduinolibs/libraries/Crypto/XOF.cpp -Iarduinolibs/libraries/Crypto -o build/xof.o

keccakcore.o: arduinolibs/libraries/Crypto/KeccakCore.cpp
	g++ -std=c++11 -c arduinolibs/libraries/Crypto/KeccakCore.cpp -Iarduinolibs/libraries/Crypto -o build/keccakcore.o
