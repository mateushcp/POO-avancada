# C-POO-avan-ada

FILA EM C++

DECORADOR DE FORMAS

CorDecorator adiciona uma cor a forma. Como não iremos fazer o desenho, o efeito desse método deve ser adicionar uma linha ao arquivo de saída com o seguinte formato " - cor: ?" onde a interrogação é uma cor parametrizada.
OpacidadeDecorator adiciona possíveis opacidades a forma. Como não iremos fazer o desenho, o efeito desse método deve ser adicionar uma linha ao arquivo de saída com o seguinte formato "  - opacidade: ?" onde a interrogação é parametrizada seguindo as especificações do OpacidadeDecorator.hpp .:  * Para valores de 0 a 0.33 (inclusive) a opacidade deve receber valor "baixa"
   * Para valores de 0.33 a 0.66 (inclusive), a opacidade deve receber valor "média"
   * Para valores de 0.66 a 1 (inclusive), a opacidade deve receber valor "alta"
   Valores fora desse intervalo não são classificados como opacidade, e não devem alterar o método desenha().
TamanhoDecorator modifica o tamanho da forma. Dado uma forma qualquer, esse método adiciona uma linha ao arquivo de saída com o seguinte formato " - tamanho: ?" onde a interrogação é um tamanho parametrizado.

Para testar sua implementação, use o programa abaixo:

#include <iostream>
#include "ConcreteForma.hpp"
#include "CorDecorator.hpp"
#include "TamanhoDecorator.hpp"
#include "OpacidadeDecorator.hpp"

AbstractForma* criaFormaCompleta(std::string forma, std::string cor, int tamanho, double opacidade) {
  AbstractForma* abs = new ConcreteForma(forma);
  abs = new TamanhoDecorator(abs, tamanho);
  abs = new CorDecorator(abs, cor);
  return new OpacidadeDecorator(abs, opacidade);
}
AbstractForma* adicionarTamanho(std::string forma, int tamanho) {
  AbstractForma* abs = new ConcreteForma(forma);
  return new TamanhoDecorator(abs, tamanho);
}
AbstractForma* adicionarCor(std::string forma, std::string cor) {
  AbstractForma* abs = new ConcreteForma(forma);
  return new CorDecorator(abs, cor);
}
AbstractForma* adicionarOpacidade(std::string forma, double opacidade) {
  AbstractForma* abs = new ConcreteForma(forma);
  return new OpacidadeDecorator(abs, opacidade);
}
bool is_int(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
bool is_double(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0';
}
int main() {
  std::string forma;
  std::getline(std::cin, forma);
  std::cout << adicionarCor(forma, "azul")->desenha() << std::endl;
  std::cout << adicionarTamanho(forma, 12)->desenha() << std::endl;
  std::cout << adicionarOpacidade(forma, 0.66)->desenha() << std::endl;
  std::cout << criaFormaCompleta(forma, "verde", 13, 2.1)->desenha() << std::endl;
 
  std::getline(std::cin, forma);
  AbstractForma* abs = new ConcreteForma(forma);
  std::string opcao;
  while(std::cin >> opcao){
        if(is_int(opcao)){
            abs = new TamanhoDecorator(abs, std::stoi(opcao));
        }
        else if(is_double(opcao)){
            abs = new OpacidadeDecorator(abs, std::stod(opcao));
        }
        else{
            abs = new CorDecorator(abs, opcao);
        }
  }
  std::cout << abs->desenha() << std::endl;
 
}
Para guiar a implementação, o decorador CorDecorator já está implementado. Você pode se basear na implementação dele para implementar os outros dois decoradores. O arquivo de implementação segue abaixo:

#include "CorDecorator.hpp"
std::string CorDecorator::desenha() {
  return FormaDecorator::desenha() + "\n- cor: " + this->_cor;
}
void CorDecorator::setCor(std::string cor) {
  this->_cor = cor;
}
std::string CorDecorator::getCor() {
  return this->_cor;
}

Abaixo são vistos alguns casos de teste que você pode usar como exemplo:
A entrada consiste de duas formas.
Para a primeira o arquivo main utiliza os decoradores para adicionar cor, tamanho e opacidade com valores já definidos (inclusive combinando-os) - veja o arquivo main.
Para a segunda forma o arquivo main lê os parâmetros que serão passados ao CorDecorator, TamanhoDecorator e OpacidadeDecorator (verificando se são doubles ou inteiros para o segundo e terceiro caso respectivamente)

Entrada:
bola
caixa
12
azul
branco
13
roxo
amarelo
19
0.2
0.8
2.3

Saída:
bola
- cor: azul
bola
- tamanho: 12
bola
- opacidade: média
bola
- tamanho: 13
- cor: verde
caixa
- tamanho: 12
- cor: azul
- cor: branco
- tamanho: 13
- cor: roxo
- cor: amarelo
- tamanho: 19
- opacidade: baixa
- opacidade: alta



![image](https://user-images.githubusercontent.com/56733190/112527558-f378a600-8d81-11eb-81c1-dd3f2ac4250b.png)


