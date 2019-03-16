#include <stdio.h>

int main(int argc, char* argv[]){
	
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'M';
	char first_name[] = "Oliwer";
	char last_name[] = "Sobolewski";
	
	first_name[3] = 'O';
	
	printf("Jesteś %d kilometrów stąd.\n", distance);
	printf("Your power level is over %f thousand.\n",power);
	printf("Masz %f ekstra super mocy.\n", super_power);
	printf("Inicjał to %c.\n", initial);
	printf("Moje imię to %s\n", first_name);
	printf("Moje nazwisko to %s.\n", last_name);
	printf("Moje pełne imię i nazwisko to %s %c. %s.\n", first_name, initial, last_name);
	
	int bugs = 100;
	double bug_rate = 1.2;
	
	printf("Masz %d bugów na abstrakcyjnym poziomie %f.\n", bugs, bug_rate);
	
	long universe_of_defects = 1L*1024L*1024L*1024L;
	
	printf("W całym wszechświecie jest %ld bugów.\n", universe_of_defects);
	
	double expected_bugs = bugs * bug_rate;
	
	printf("Będziesz miał %f bugów.\n", expected_bugs);
	
	double part_of_the_universe = expected_bugs / universe_of_defects;
	
	printf("To tylko %e część całego wszechświata.\n", part_of_the_universe);
	
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("powinieneś się tym przejmować w %s%%.\n", nul_byte);
	
	return 0;
}