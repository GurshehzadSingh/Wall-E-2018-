#ifndef CALIBRACAO2_H
#define CALIBRACAO2_H

#include <robo_hardware2.h> 
#include "SensorDeCor.h"
#include "Refletancia.h"

#include "Sala3.h"
 
class Calibracao2 {
	
private:
	Matematica calcule;
	calibracao_dados cali;

	bool realizarCali;
	
	const char SAIDA = 'S'; 
	

	void posicionar_sensores();
	void posicionar_sala3();
	
	

	void esperarParaLer();
	void calibrarBranco();
	void calibrarPreto();
	
	void calibrarCor();
	void calibrarCorPreto();
	void calibrarCorBranco();
	void calibrarVerde();
	void calibrarCinza();

	void calibrarSala3();

	char escolhaSala3;

	char escolhaInicial;
	char escolhaMenu;
	char escolhaBrancoPreto;

	char escolhaPreto;
	char escolhaBranco;
	
	char escolhaCor;
	char controlador;

  
public:
 
	Calibracao2();

	void Menu_calibrar();
	void lerCalibracao();
	
protected: 
	Refletancia refletancia_dir, refletancia_dir2, refletancia_esq, refletancia_esq2;
	SensorDeCor corDireito, corEsquerdo;

	Sala3 sala3;
};

#endif