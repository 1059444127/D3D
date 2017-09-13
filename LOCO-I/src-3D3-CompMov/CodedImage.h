 /**
  @file CodedImage.h

  @author Felipe Tambasco, Mauro Barbosa
  @date Feb, 2017

*/

#ifndef CODEDIMAGE_H_
#define CODEDIMAGE_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <bitset>
#include <unistd.h>


#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <math.h>

namespace std {

class CodedImage {
public:
	CodedImage();
	CodedImage(int, int);
	CodedImage(string);
	CodedImage(string, string);
	virtual ~CodedImage();

	void loadImage();
		void setMagic(ifstream&,char&);
		void setCompMov(ifstream&,char&);
		void setWidth(ifstream&,char&,bool);
		void setHeigth(ifstream&,char&,bool);
		void setWhite(ifstream&,char&,bool);
		void setNmax(ifstream&,char&);
		void setCantidadImagenes(ifstream&,char&);

		string path;

		string name;

		string magic;

		int width;
		int heigth;
		int v_width;
		int v_heigth;
		int v_white;

		int cantidad_imagenes;

		int white;

		/* esta variable representa la imagen codificada, es un array de chars donde cada elemento es
		cada byte leido del archivo */
		char *image;

		int Nmax;

		bool activarCompMov=false;
};

} /* namespace std */

#endif /* CODEDIMAGE_H_ */