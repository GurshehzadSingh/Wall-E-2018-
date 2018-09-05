#include "Calibracao2.h"


Calibracao2::Calibracao2(){
	escolhaInicial = ' ';
	escolhaMenu = ' ';
	escolhaBranco = ' ';
	escolhaPreto = ' ';
	escolhaSala3 = ' ';
}


void Calibracao2::esperarParaLer (){
  while (!Serial.available()){}
}

void Calibracao2::calibrarVerde(){
	
	Serial.println(F(" COLOQUE O SENSOR DIREITO NO VERDE: "));
	Serial.println(F("[D] Calibrar VERDE DIREITO"));
	
	esperarParaLer();
	controlador = Serial.read();

	
	if (controlador == 'D') {
		corDireito.setVerde(robo.getHSVDireito());
	}
	
	Serial.println(F( "COLOQUE O SENSOR ESQUERDO NO VERDE: "));
	Serial.println(F("[E] Calibrar VERDE ESQUERDO"));

	esperarParaLer();
	controlador = Serial.read();


	if (controlador == 'E'){
		corEsquerdo.setVerde(robo.getHSVEsquerdo()); 
	}
	
	controlador = ' ';
	
}


void Calibracao2::calibrarCorPreto(){
	
	Serial.println(F(" COLOQUE O SENSOR DIREITO NO PRETO: "));
	Serial.println(F("[D] Calibrar PRETO DIREITO"));
	
	esperarParaLer();
	controlador = Serial.read();

	if (controlador == 'D') {
		corDireito.setPreto(robo.getHSVDireito());
	}
	
	Serial.println(F( "COLOQUE O SENSOR ESQUERDO NO PRETO: "));
	Serial.println(F("[E] Calibrar PRETO ESQUERDO"));
	
	esperarParaLer();
	controlador = Serial.read();
	

	if (controlador == 'E'){
		corEsquerdo.setPreto(robo.getHSVEsquerdo()); 
	}
	
	controlador = ' ';
	
}

void Calibracao2::calibrarCorBranco(){
	
	Serial.println(F(" COLOQUE OS SENSORES NO BRANCO: "));
	Serial.println(F("[B] Calibrar COR BRANCO"));
	
	esperarParaLer();
	controlador = Serial.read();
	

	if (controlador == 'B') {
		corDireito.setBranco(robo.getHSVDireito());
		corEsquerdo.setBranco(robo.getHSVEsquerdo());
	}

	controlador = ' ';
}

void Calibracao2::calibrarCinza(){
	
	Serial.println(F(" COLOQUE OS SENSORES NO CINZA: "));
	Serial.println(F("[C] Calibrar COR CINZA"));
	
	esperarParaLer();
	controlador = Serial.read();

	if (controlador == 'C') {
		corDireito.setCinza(robo.getHSVDireito());
		corEsquerdo.setCinza(robo.getHSVEsquerdo());
	}
	
	controlador = ' ';
}


void Calibracao2::calibrarCor(){

//  	robo.habilitaTCS34();
//	Serial.println(robo.getSensor() == TCS34 ? "tcs34":"tsc23");
	while (escolhaCor != SAIDA){
		Serial.println(F("[V] Para calibrar o VERDE"));
		Serial.println(F("[C] Para calibrar o CINZA"));
		Serial.println(F("[B] Para calibrar o BRANCO"));
		Serial.println(F("[P] Para calibrar o PRETO"));
		Serial.println(F("[M] MENU INICIAL"));
		Serial.println(F("[S] SAIR"));
		
		esperarParaLer();
		escolhaCor = Serial.read();

		switch (escolhaCor) {
		
			case 'V':
				calibrarVerde();
				break;
			case 'C':
				calibrarCinza();
				break;
			case 'B':
				calibrarCorBranco();
				break;
			case 'P':
				calibrarCorPreto();
				break;
			case 'M':
				Menu_calibrar();
				break;
			default:
				escolhaCor = SAIDA;
		}
	}
	escolhaCor = ' ';
}

void Calibracao2::calibrarBranco(){

  while (escolhaBranco != SAIDA) {
    Serial.println(F("\nColoque todos os sensores no BRANCO"));
    
    posicionar_sensores();

    Serial.println(F("[C] Para CALIBRAR"));
    Serial.println(F("[S] Para SAIR"));
    
    esperarParaLer();
    escolhaBranco = Serial.read();

    if (escolhaBranco == 'C') {
	  refletancia_dir.setBrancoMini(robo.lerSensorLinhaDir());
	  refletancia_dir2.setBrancoMini(robo.lerSensorLinhaMaisDir());
	  refletancia_esq.setBrancoMini(robo.lerSensorLinhaEsq());
	  refletancia_esq2.setBrancoMini(robo.lerSensorLinhaMaisEsq());

	  Serial.println("  ");
      Serial.println(F("Valores lidos: "));
      Serial.print(refletancia_esq2.getMinimoBranco());
      Serial.print(F(" --- "));
      Serial.print(refletancia_esq.getMinimoBranco());
      Serial.print(F(" --- "));
      Serial.print(refletancia_dir.getMinimoBranco());
      Serial.print(F(" --- "));
      Serial.println(refletancia_dir2.getMinimoBranco());
      Serial.println(F(" "));
      
          
    }
    else {
      escolhaBranco = SAIDA;
    }
  }
}


void Calibracao2::calibrarPreto(){

	while (escolhaPreto != SAIDA) {
		Serial.println(F("\nColoque todos os sensores no PRETO"));

		posicionar_sensores();

		Serial.println(F("[C] Para CALIBRAR"));
		Serial.println(F("[S] Para SAIR"));
		
		esperarParaLer();
		escolhaPreto = Serial.read();

    if (escolhaPreto == 'C') {
	  refletancia_dir.setPretoMax(robo.lerSensorLinhaDir());
	  refletancia_dir2.setPretoMax(robo.lerSensorLinhaMaisDir());
	  refletancia_esq.setPretoMax(robo.lerSensorLinhaEsq());
	  refletancia_esq2.setPretoMax(robo.lerSensorLinhaMaisEsq());
	  
	  Serial.println("  ");
      Serial.println(F("Valores lidos: "));
      Serial.print(refletancia_esq2.getMaximoPreto());
      Serial.print(F(" --- "));
      Serial.print(refletancia_esq.getMaximoPreto());
      Serial.print(F(" --- "));
      Serial.print(refletancia_dir.getMaximoPreto());
      Serial.print(F(" --- "));
      Serial.println(refletancia_dir2.getMaximoPreto());
      Serial.println(F(" "));
      
          
    }
    else {
      escolhaPreto = SAIDA;
    }
  }
  
}

void Calibracao2::posicionar_sensores() {

	Serial.println(F("\nINSIRA ALGO NO SERIAL QUANDO TODOS OS SENSORES ESTIVEREM POSICIONADOS CORRETAMENTE.\n"));
	Serial.println(F("(maisEsq)	---		(Esq)		---		(Dir)		---		(maisDir)\n"));
	
	while(1) {
		
		Serial.print(robo.lerSensorLinhaMaisEsq());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorLinhaEsq());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorLinhaDir());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorLinhaMaisDir());
		Serial.println();
		delay(1000);

		if(Serial.available()) {
		
			Serial.read();
			break;
		
		}
	}
}

void Calibracao2::posicionar_sala3() {

	Serial.println(F("\nINSIRA ALGO NO SERIAL QUANDO O ROBÔ ESTIVER POSICIONADO CORRETAMENTE.\n"));
	Serial.println(F("(esquerda)	---		(frente)		---		(direita)\n"));

	while(1) {

		Serial.print(robo.lerSensorSonarEsq());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorSonarFrontal());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorSonarDir());
		Serial.println();
		delay(1000);

		if(Serial.available()) {

			Serial.read();
			break;

		}

	}

}

void Calibracao2::calibrarSala3() {

	while (escolhaSala3 != SAIDA) {

		Serial.println(F("\nColoque o robô na Sala 3."));

		posicionar_sala3();

		Serial.println(F("[C] Para CALIBRAR"));
		Serial.println(F("[S] Para SAIR"));

		esperarParaLer();
		escolhaSala3 = Serial.read();

	    if (escolhaSala3 == 'C') {

	    	sala3.setLimiteLateral(robo.lerSensorSonarEsq());
	    	sala3.setLimiteFrontal(robo.lerSensorSonarFrontal());

			Serial.println("  ");
			Serial.println(F("Valores lidos: "));
			Serial.print(sala3.getLimiteLateral());
			Serial.print(F(" --- "));
			Serial.print(sala3.getLimiteFrontal());
	      
	    }
	    else {
	      escolhaSala3 = SAIDA;
	    }

	}

}

void Calibracao2::Menu_calibrar() {
	
	while (escolhaInicial != SAIDA) { 

		Serial.println(F("[C] Começar calibração"));
		Serial.println(F("[S] Sair da calibração"));

		esperarParaLer();
		escolhaInicial = Serial.read();

		if (escolhaInicial == 'C') {

			while (escolhaMenu != SAIDA) { 

				Serial.println(F("[B] Calibrar BRANCO REFLETÂNCIA"));
				Serial.println(F("[P] Calibrar PRETO REFLETÂNCIA"));
				Serial.println(F("[C] Calibrar COR"));
				Serial.println(F("[T] Sala 3"));
				Serial.println(F("[S] SAIR"));

				esperarParaLer();
				escolhaMenu = Serial.read();

				switch(escolhaMenu) {
					case 'B':
						calibrarBranco();  
						break;
					case 'P':
						calibrarPreto();
						break;
					case 'C':
						calibrarCor();
						break;
					case 'T':
						calibrarSala3();
				}

			}

			escolhaMenu = ' ';

			refletancia_esq2.calculeMedia();
			refletancia_esq.calculeMedia();
			refletancia_dir.calculeMedia();
			refletancia_dir2.calculeMedia();

			cali.refletanciaDir = refletancia_dir.getSeparacao();
			cali.refletanciaMaisDir = refletancia_dir2.getSeparacao();
			cali.refletanciaEsq = refletancia_esq.getSeparacao();
			cali.refletanciaMaisEsq = refletancia_esq2.getSeparacao();

			cali.brancoEsq = corEsquerdo.getBranco();
			cali.brancoDir = corDireito.getBranco();

			cali.pretoEsq = corEsquerdo.getPreto();
			cali.pretoDir = corDireito.getPreto();

			cali.verdeEsq = corEsquerdo.getVerde();
			cali.verdeDir = corDireito.getVerde();

			// SALA 3

			cali.sala3_limiteLateral = sala3.getLimiteLateral();
			cali.sala3_limiteFrontal = sala3.getLimiteFrontal();

			robo.salvarCalibracao(cali);

		}
	}
		 
}
 
 
 void Calibracao2::lerCalibracao(){
	 robo.lerCalibracao(cali);
	  
	  refletancia_dir.setMedia(cali.refletanciaDir);
	  refletancia_dir2.setMedia(cali.refletanciaMaisDir);
	  refletancia_esq.setMedia(cali.refletanciaEsq);
	  refletancia_esq2.setMedia(cali.refletanciaMaisEsq);
	  
	  corEsquerdo.setBranco(cali.brancoEsq); 
	  corDireito.setBranco(cali.brancoDir);
	  
	  corEsquerdo.setPreto(cali.pretoEsq);
	  corDireito.setPreto(cali.pretoDir);
	  
	  corEsquerdo.setVerde(cali.verdeEsq);
	  corDireito.setVerde(cali.verdeDir);


	  Serial.println(F("\nSENSORES:\n"));
	  Serial.println(F("(maisEsq)	---		(Esq)		---		(Dir)		---		(maisDir)\n"));
	  Serial.println(refletancia_esq2.getSeparacao());
	  Serial.print(F("		---		"));
	  Serial.println(refletancia_esq.getSeparacao());
	  Serial.print(F("		---		"));
	  Serial.println(refletancia_dir.getSeparacao());
	  Serial.print(F("		---		"));
	  Serial.println(refletancia_dir2.getSeparacao());

	  sala3.setLimiteLateral(cali.sala3_limiteLateral);
	  sala3.setLimiteFrontal(cali.sala3_limiteFrontal);

	  Serial.println(F("\nSALA3:\n"));
	  Serial.println(F("(limiteLateral)	---		(limiteFrontal)\n"));
	  Serial.println(sala3.getLimiteLateral());
	  Serial.print(F("		---		"));
	  Serial.println(sala3.getLimiteFrontal());


 }
 


	
