#ifndef SALA3_H	
#define SALA3_H

#include <robo_hardware2.h>
#include "Motores.h"

class Sala3 {
	private:
		float limite_lateral;
		float limite_frontal;

		float distanciaAtual;

		// Dependendo da posicao da rampa
		int fator_esq;
		int fator_dir;

		bool viu_bola;

		Motores motores;

		void alinharParede(int qnt);

		void procurarBola();

		void encostarRobo();

	public:

		Sala3();

		void portal();

		void executar(int args);

		void setLimiteLateral(float valorLido);
		void setLimiteFrontal(float valorLido);
		
		float getLimiteLateral();
		float getLimiteFrontal();

};

#endif