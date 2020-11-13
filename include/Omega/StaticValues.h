#pragma once
#include <string>

///////////////////////////////////////////////////////////////
// c'est ici que sont stoqu�e toutes les donn�es importante
// tel que la localisation des fichiers ou encore la valeur
// de PI ou autres
namespace STATIC {

	namespace MATH
	{

		const double PI = 3.1415926535897932384626433832795;
		const double PI_x2 = 3.1415926535897932384626433832795 * 2.0;
		const double PI_2 = 3.1415926535897932384626433832795 / 2.0;
		const double PI_4 = 3.1415926535897932384626433832795 / 4.0;
		const double DEG_RAD = 180.0 / PI;
		const double RAD_DEG = PI / 180.0;


	}

	namespace SYS
	{

		const double WIDTH = 1920.0;
		const double HIGHT = 1080.0;
		const double HALF_WIDTH = WIDTH / 2.0;
		const double HALF_HEIGHT = HIGHT / 2.0;

	}
}

