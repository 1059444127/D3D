 /**
  @file Decoder.h

  @author Felipe Tambasco, Mauro Barbosa
  @date Feb, 2017

*/


#ifndef DECODER_H_
#define DECODER_H_

#include "CodedImage.h"
#include "Image.h"
#include "Context.h"
#include "ContextRun.h"
#include "Racha.h"

namespace std {

class Decoder {
public:


	typedef struct pixels{

			int a;
			int b;
			int c;
			int d;

		} pixels;

		typedef struct grad_struct{

			int ga;
			int gb;
			int gc;

		} grad;

		typedef struct pixels3D{

						int a;
						int b;
						int c;
						int d;
						int a_;
						int b_;
						int c_;
						int d_;
						int e_;
						int f_;
						int g_;

			} pixels3D;

		Decoder(CodedImage);
			virtual ~Decoder();
			void decode();
		pixels getPixels(int, Image&);
		pixels getPixels_(int, Image&);
		pixels3D getPixels3D(int,int, Image&);
		int getP(pixels);
		grad setGradients(pixels);
		grad getGradients3D(int,pixels3D);
		void setContextsArray();
		int getContext(grad, int&);
		int getContext_(int, int, Image&);
		int getContext(grad,grad, int&, bool&);
		int getPredictedValue(pixels);
		int getPredictedValue(int, pixels3D);
		int getK(int);
		int getKPrime(Racha&);
		void updateContexto(int, int);
		void updateContexto_(int, int,int);
		void writeHeader(ofstream&);
		void writeWidth(ofstream&);
		void writeHeigth(ofstream&);
		void writeWhite(ofstream&);
		void writeMagic(ofstream&);
		void updateImage(int, int,Image&);
		int unRice(int,float,int);
		int unrice_rachas(int,int,int);
		void completaArray();
		int getBit();
		int getError(int,int,int);
		int getError_(int);
		int getRachaParams(int, int&,int&);
		int getRachaParams2(int, int&,int&);
		void updateImageRacha(Racha&, int, ofstream&, Image&);
		void updateImageInterruption(Racha&, int,int, ofstream&, int, Image&);
		int reduccionDeRango(int, int,int);
		int clipErrorEstadisticos(int);
		Image setInitialImage();
		int fixPrediction(int,int, int);
		float get_s(int);
		int getProxImageAnterior(int);
		int selectMED(grad);
		string str_(int n);

		/* Este objeto representa la imagen codificada que está decodificando */
		CodedImage codedImage;
		/* Esta variable lleva la cuenta de los bytes leídos de codedImage */
		int codedImagePointer=0;
		int Nmax;
		int i;

		static const int CANTIDAD_MAXIMA_CONTEXTOS=9*9*9*9*9;

		Context contexts[CANTIDAD_MAXIMA_CONTEXTOS];


	string file;

	Image images[50]; //hacerlo bien después
	int cantidad_imagenes;

	Image prev;

	//Image image;
	//Image image2;

	/* Algún tamaño apropiado
	Array auxiliar para poder trabajar con los bits individuales de la imagen codificada */
	bool fileToBits[800];

	/* Puntero que señala el próximo lugar a leer de decode */
	int fileToBitsPointer=0;

	bool racha;

	int J[32]={0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,5,5,6,6,7,7,8,9,10,11,12,13,14,15};

	int kr=0;
	int m_r=1;

	bool debug=false;
	bool debug4=false;

	/**
	 *
	 * CAMBIOS !
	 *
	 *
	 */

	int range;

	int Lmax;	//agregados también al constructor de clase Coder(image, int, int)
	int beta;
	int qMax;
	int qMax_;
	int RUNcnt;
	int RUNindex = 0;
	bool golombLimitado(int);

	ContextRun cntx[2];    // Contextos especiales para rachas.
};

} /* namespace std */

#endif /* DECODER_H_ */