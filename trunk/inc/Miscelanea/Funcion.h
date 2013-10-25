#pragma once

class Funcion {
	
	public:
		Funcion ();
		
		virtual float evaluar_en (float x);
		
		virtual float get_x_min () { return 0.0; };

		virtual float get_x_max () { return 0.0; };
		
		virtual ~Funcion ();
		
};

