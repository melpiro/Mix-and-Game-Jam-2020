#pragma once

#include <vector>
#include <iostream>
#include <fstream> 
#include <sstream>
#include "String/StringFunctions.h"


namespace O{
	namespace file {

		std::string readLigne(const std::string& fichier, const int& ligne);

		void writeAllLinesAtEnd(const std::string& fichier, std::vector<std::string> allLines);
		void writeAllLines(const std::string& fichier, std::vector<std::string> allLines);
		
		template<typename T>
		void writeAtEnd(const std::string& fichier, const T& data, const std::string& end = "");

		template<typename T>
		void write(const std::string& fichier, const  T& data, const std::string& end = "");

		template<typename T>
		void writeAtEnd(const std::string& fichier, const std::vector<T>& data, const std::string& separator = " ", const std::string& end = "");
		template<typename T>
		void write(const std::string& fichier, const  std::vector<T>& data, const std::string& separator = " ", const std::string& end = "");
		

		///////////////////////////////////////////////////////////////
		// attention ne pas utilise cette methode si l'argument
		// readStream a déja fait un readLine() ou va faire
		// un readLine() dans le future
		template<typename T>
		void readVector(std::ifstream& readStream, std::vector<T>& vector, size_t nbElement);


		int getNbLigne(const std::string& fichier);

		void deleteContent(const std::string& fichier);

		///////////////////////////////////////////////////////////////
		// indexCorelation = true -> index 1 -> ligne 1
		// indexCorelation = false -> index 0 -> ligne 1
		std::vector<std::string> getAllLines(const std::string& fichier, bool indexCorelation = true);

		std::ifstream getReadSteam(const std::string& file);
		std::ofstream getWriteSteam(const std::string& file);
		std::ofstream getWriteSteamApp(const std::string& file);
		std::ofstream getWriteSteamBinary(const std::string& file);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		template<typename T>
		void writeAtEnd(const std::string& fichier, const T& data, const std::string& end)
		{
			std::ofstream flux(fichier.c_str(), std::ios::app);

			if (!flux.is_open())
			{
				std::cerr << "[O::file::writeAtEnd] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return ;
			}

			flux << data << end; 
			flux.close();

		}

		template<typename T>
		void write(const std::string& fichier, const  T& data, const std::string& end)
		{
			std::ofstream flux(fichier.c_str());

			if (!flux.is_open())
			{
				std::cerr << "[O::file::write] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return ;
			}

			flux << data << end;
			flux.close();
		}

		template<typename T>
		void writeAtEnd(const std::string& fichier, const std::vector<T>& data, const std::string& separator, const std::string& end)
		{
			std::ofstream flux(fichier.c_str(), std::ios::app);

			if (!flux.is_open())
			{
				std::cerr << "[O::file::writeAtEnd T=std::vector] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return ;
			}
			for (size_t i = 0; i < data.size(); i++)
			{
				if (i + 1 == data.size()) flux << data[i] << end;
				else flux << data[i] << separator;
			}
			flux.close();
		}
		template<typename T>
		void write(const std::string& fichier, const  std::vector<T>& data, const std::string& separator, const std::string& end)
		{
			std::ofstream flux(fichier.c_str());

			if (!flux.is_open())
			{
				std::cerr << "[O::file::write T=std::vector] impossible d'ouvrir le fichier : "<< fichier << '\n';
				return ;
			}
			for (size_t i = 0; i < data.size(); i++)
			{
				if (i + 1 == data.size()) flux << data[i] << end;
				else flux << data[i] << separator;
			}
			flux.close();
		}


		template<typename T>
		void readVector(std::ifstream& readStream, std::vector<T>& vector, size_t nbElement)
		{

			if (!readStream.is_open())
			{
				std::cerr << "[O::file::readVector] le flux readStream, ne pointe sur aucun fichier !\n";
				return;
			}
			if (vector.size() > 0)
			{
				std::cerr << "[O::file::readVector] vector non vide !\n";
				return;
			}
			for (size_t i = 0; i < nbElement; i++)
			{
				T elem;
				readStream >> elem;
				vector.push_back(elem);
			}
		}
	}
}