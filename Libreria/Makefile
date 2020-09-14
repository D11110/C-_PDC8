# all:
#  g++ Programa.cpp \
#  MiLibreria.cpp \
#  -o Programa
# cleanup:
#  rm Programa
#  #del Programa.exe
all:
 g++ -fpic \
 -c MiLibreria.cpp \
 -o MiLibreria.o
 g++ -shared \
 MiLibreria.o \
 -o libMiLibreria.so
 #-o MiLibreria.dll
 g++ Programa.cpp \
 -L. -lMiLibreria \
 -o Programa
cleanup:
 rm MiLibreria.o
 rm libMiLibreria.so
 rm Programa 