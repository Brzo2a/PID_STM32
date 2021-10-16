/*
 * PID.c
 */
#include "PID.h"

void init_pid(pid_str *data, float kp_init, float ki_init, float kd_init, float anti_windup_init) //inicjacja regulatora
{
	data->poprzedni_uchyb = 0;
	data->suma_uchybu = 0;

	data->Kp = kp_init;
	data->Ki = ki_init;
	data->Kd = kd_init;

	data->anti_windup = anti_windup_init;
}

void pid_reset(pid_str *data)		//reset parametrów regulatora
{
	data->suma_uchybu = 0;
	data->poprzedni_uchyb = 0;
}



float pid_oblicz(pid_str *data, float wartosc_zadana, float pomiar) //oblicza wartość regulatora PID
{
	float uchyb;
	float p_temp, i_temp, d_temp;

	uchyb = wartosc_zadana - pomiar;		//obliczenie uchybu
	data->suma_uchybu += uchyb;			    //sumowanie uchybu

	p_temp = (float)(data->Kp * uchyb);		//człon proporcjonalny
	i_temp = (float)(data->Ki * data->suma_uchybu);	//człon całkujący
	d_temp = (float)(data->Kd * (uchyb - data->poprzedni_uchyb));//człon różniczkujący

	if(data->suma_uchybu >= data->anti_windup) data->suma_uchybu = data->anti_windup;	//ograniczenie członu całkującego
	else if(data->suma_uchybu <= -data->anti_windup) data->suma_uchybu = -data->anti_windup;

	data->poprzedni_uchyb = uchyb;	//zapisanie poprzedniej wartości uchybu

	return (float)(p_temp + i_temp + d_temp);		//odpowiedź regulatora
}
