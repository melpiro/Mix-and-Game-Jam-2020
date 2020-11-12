#include "Files/FileFunctions.h"

namespace O{
	namespace file {
		///////////////////////////////////////////////////////////////
		std::string readLigne(const std::string& fichier, const int& ligne)
		{
			std::string res("");        // resutlat final
			std::ifstream flux(fichier);

			if (!flux.is_open())
			{
				std::cerr << "[O::file::readLigne] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return "";
			}

			for (int i(0); i < ligne; i++)
			{
				if (!std::getline(flux, res))
				{
					std::cerr << "[O::file::readLigne] lecture en dehors des limites du fichier "<< fichier << '\n';
					return "";
				}
			}
			flux.close();
			
			O::str::remplace(res, "\\n", "\n");
			return res;
		}
		///////////////////////////////////////////////////////////////
		int getNbLigne(const std::string& fichier)
		{
			std::ifstream in(fichier, std::ios::in);
			if (!in.is_open())
			{
				std::cerr << "[O::file::getNbLigne] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return 0;
			}

			std::string s;
			int nbLignes(0);
			while (std::getline(in, s))
			{
				nbLignes++;
			}
			in.close();
			return nbLignes;
		}
		///////////////////////////////////////////////////////////////
		void deleteContent(const std::string& fichier)
		{
			std::ofstream flux(fichier.c_str());
			if (!flux.is_open())
			{
				std::cerr << "[O::file::deleteContent] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return;
			}
			flux.close();
		}

		///////////////////////////////////////////////////////////////
		std::vector<std::string> getAllLines(const std::string& fichier, bool indexCorelation)
		{
			std::vector<std::string> res(0);        // resutlat final
			if (indexCorelation) res.push_back(""); // pour décaler les index
			std::ifstream flux(fichier);
			if (!flux.is_open())
			{
				std::cerr << "[O::file::getAllLines] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return std::vector<std::string>();
			}

			std::string s;
			while (std::getline(flux, s))
			{
				O::str::remplace(s, "\\n", "\n");
				res.push_back(s);
			}
			flux.close();
			return res;
		}
		void writeAllLinesAtEnd(const std::string& fichier, std::vector<std::string> allLines)
		{
			std::ofstream flux(fichier.c_str(), std::ios::app);
			for (size_t i = 0; i < allLines.size(); i++)
			{
				flux << allLines[i] << '\n';
			}
			flux.close();
		}
		void writeAllLines(const std::string& fichier, std::vector<std::string> allLines)
		{
			std::ofstream flux(fichier.c_str());
			for (size_t i = 0; i < allLines.size(); i++)
			{
				flux << allLines[i] << '\n';
			}
			flux.close();
		}

		std::ifstream getReadSteam(const std::string& file)
		{
			return std::ifstream(file.c_str());
		}
		std::ofstream getWriteSteam(const std::string& file)
		{
			return std::ofstream(file.c_str());
		}
		std::ofstream getWriteSteamApp(const std::string& file)
		{
			return std::ofstream(file.c_str(), std::ios::app);
		}
		std::ofstream getWriteSteamBinary(const std::string& file)
		{
			return std::ofstream(file.c_str(), std::ios::binary);
		}
	}
}