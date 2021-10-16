/*
 * PID.h
 */




typedef struct
{
	float poprzedni_uchyb; 	//Poprzedni uchyb
	float suma_uchybu;		//Suma uchybów
	float Kp;				//Wzmocnienie członu proporcjonalnego
	float Ki;				//Wzmocnienie członu całkującego
	float Kd;				//Wzmocnienie członu różniczkującego
	float anti_windup;		//ograniczenie członu całkującego
}pid_str;


void init_pid(pid_str *data, float kp_init, float ki_init, float kd_init, float anti_windup_init); //inicjacja regulatora

void pid_reset(pid_str *data);		//reset parametrów regulatora

float pid_oblicz(pid_str *data, float wartosc_zadana, float pomiar); //oblicza wartość regulatora PID


