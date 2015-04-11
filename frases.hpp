#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Frases {

private:

  float tiempo;
  sf::Font font;
  float velocidad;
  vector<string> frases;

  float computaEscala(float h,float despobjeto);

  void dibujafrase(int centropantalla,int hobservador,int despobservador,
                   int numfrase,int desp,int hcaracter,string &frase,sf::RenderWindow &window);

public:

  Frases();

  void dibujafrases(int centropantalla,int hobservador,int despobservador,int hcaracter,
		    sf::RenderWindow &window,float delta);

  void run(sf::RenderWindow & window);
};
