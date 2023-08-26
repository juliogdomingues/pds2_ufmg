#include "doctest.h"

#include "forma.h"
#include "forma2d.h"
#include "quadrado.h"
#include "triangulo.h"
#include "forma3d.h"
#include "cubo.h"
#include "esfera.h"
#include "circulo.h"

#include <string>
#include <math.h>


TEST_CASE("01 - Testando construção de classes derivadas com seus respectivos atributos") {
    //construtores devem setar o nome das formas. Exemplo, ao criar um quadrado, o campo quadrado
    //deve receber o valor "quadrado"
    
    CHECK_NOTHROW(Triangulo("azul", 10, 12, 5)); //construtor com cor, aresta_1, aresta_2 e aresta_3
    CHECK_NOTHROW(Quadrado("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Cubo("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Esfera("verde", 4)); //construtor com cor e raio
    CHECK_NOTHROW(Circulo("verde", 4)); //construtor com cor e raio

}

TEST_CASE("02 - Acessando métodos das classes base") {
    Triangulo t("azul", 6, 7, 8);
    CHECK((abs(t.get_area()-20.3331625676))<0.0001);
    CHECK(t.get_perimetro() == 21);
    
    Quadrado q("verde", 4);
    CHECK(q.get_area() == 16);
    CHECK(q.get_perimetro() == 16);
    
    Cubo c("roxo", 4);
    CHECK(c.get_volume() == 64);
    
    Esfera e("amarelo", 3);
    CHECK(abs(e.get_volume()-113.097)<0.01);
    
    Circulo cr("rosa", 2);
    CHECK(abs(cr.get_area()-12.5664)<0.001);
    CHECK(abs(cr.get_perimetro()-12.5664)<0.001);

}

TEST_CASE("03 - Instanciando objetos com classe base") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    std::string nome1 = "triangulo";
    std::string nome2 = "quadrado";
    std::string nome3 = "esfera";
    std::string nome4 = "cubo";
    std::string nome5 = "circulo";
    
    Forma *poligono1 = &quadrado;
    Forma *poligono2 = &triangulo;
    Forma *poligono3 = &esfera;
    Forma *poligono4 = &cubo;
    Forma *poligono5 = &circulo;
    
    //checando nomes
    CHECK(nome2.compare(poligono1->get_nome())==0);
    CHECK(nome1.compare(poligono2->get_nome())==0);
    CHECK(nome3.compare(poligono3->get_nome())==0);
    CHECK(nome4.compare(poligono4->get_nome())==0);
    CHECK(nome5.compare(poligono5->get_nome())==0);
    
    //checando cores
    CHECK(poligono1->get_cor().compare("vermelho")==0);
    CHECK(poligono2->get_cor().compare("azul")==0);
    
}

TEST_CASE("04 - Acessando métodos das classes filhas") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    Forma2D *poligono1 = &quadrado;
    Forma2D *poligono2 = &triangulo;
    Forma3D *poligono3 = &esfera;
    Forma3D *poligono4 = &cubo;
    Forma2D *poligono5 = &circulo;
    
    //checando nomes
    CHECK(poligono1->get_area()==49);
    CHECK((abs(poligono2->get_area()-9.79796))<0.001);
    CHECK(abs(poligono3->get_volume()-113.097)<0.01);
    CHECK(poligono4->get_volume()==8);
    CHECK(abs(poligono5->get_area()-12.5664)<0.001);
}

TEST_CASE("05 - Testando construção de classes derivadas com seus respectivos atributos") {
    CHECK_NOTHROW(Triangulo("azul", 10, 12, 5)); //construtor com cor, aresta_1, aresta_2 e aresta_3
    CHECK_NOTHROW(Quadrado("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Cubo("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Esfera("verde", 4)); //construtor com cor e raio
    CHECK_NOTHROW(Circulo("verde", 4)); //construtor com cor e raio
}

TEST_CASE("06 - Acessando métodos das classes base") {
    Triangulo t("azul", 6, 7, 8);
    CHECK((abs(t.get_area() - 20.3331625676)) < 0.0001);
    CHECK(t.get_perimetro() == 21);

    Quadrado q("verde", 4);
    CHECK(q.get_area() == 16);
    CHECK(q.get_perimetro() == 16);

    Cubo c("roxo", 4);
    CHECK(c.get_volume() == 64);

    Esfera e("amarelo", 3);
    CHECK(abs(e.get_volume() - 113.097) < 0.01);

    Circulo cr("rosa", 2);
    CHECK(abs(cr.get_area() - 12.5664) < 0.001);
    CHECK(abs(cr.get_perimetro() - 12.5664) < 0.001);
}

TEST_CASE("07 - Instanciando objetos com classe base") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);

    std::string nome1 = "triangulo";
    std::string nome2 = "quadrado";
    std::string nome3 = "esfera";
    std::string nome4 = "cubo";
    std::string nome5 = "circulo";

    Forma* poligono1 = &quadrado;
    Forma* poligono2 = &triangulo;
    Forma* poligono3 = &esfera;
    Forma* poligono4 = &cubo;
    Forma* poligono5 = &circulo;

    //checando nomes
    CHECK(nome2.compare(poligono1->get_nome()) == 0);
    CHECK(nome1.compare(poligono2->get_nome()) == 0);
    CHECK(nome3.compare(poligono3->get_nome()) == 0);
    CHECK(nome4.compare(poligono4->get_nome()) == 0);
    CHECK(nome5.compare(poligono5->get_nome()) == 0);

    //checando cores
    CHECK(poligono1->get_cor().compare("vermelho") == 0);
    CHECK(poligono2->get_cor().compare("azul") == 0);
}

TEST_CASE("08 - Acessando métodos das classes filhas") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);

    Forma2D* poligono1 = &quadrado;
    Forma2D* poligono2 = &triangulo;
    Forma3D* poligono3 = &esfera;
    Forma3D* poligono4 = &cubo;
    Forma2D* poligono5 = &circulo;

    //checando nomes
    CHECK(poligono1->get_area() == 49);
    CHECK((abs(poligono2->get_area() - 9.79796)) < 0.001);
    CHECK(abs(poligono3->get_volume() - 113.097) < 0.01);
    CHECK(poligono4->get_volume() == 8);
    CHECK(abs(poligono5->get_area() - 12.5664) < 0.001);
}


TEST_CASE("09 - Acessando métodos específicos da classe Esfera") {
    Esfera esfera("azul", 5);
    CHECK(abs(esfera.get_volume() - 523.598) < 0.001);
}

TEST_CASE("10 - Acessando métodos específicos da classe Esfera") {
    Esfera esfera("azul", 5);
    CHECK(abs(esfera.get_volume() - 523.598) < 0.001); // Verificar cálculo correto do volume
}

TEST_CASE("11 - Testando polimorfismo") {
    Quadrado quadrado("vermelho", 5);
    Forma* forma = &quadrado;

    CHECK(forma->get_nome() == "quadrado"); // Verificar que a função virtual retorna o nome correto da forma
    CHECK(forma->get_cor() == "vermelho"); // Verificar que a função virtual retorna a cor correta da forma

    Forma2D* forma2D = dynamic_cast<Forma2D*>(forma);
    CHECK(forma2D != nullptr); // Verificar se a conversão de ponteiro para Forma2D é bem-sucedida

    CHECK(forma2D->get_area() == 25); // Verificar que a função virtual da forma2D retorna a área correta
    CHECK(forma2D->get_perimetro() == 20); // Verificar que a função virtual da forma2D retorna o perímetro correto
}

TEST_CASE("12 - Testando polimorfismo com formas 3D") {
    Esfera esfera("amarelo", 4);
    Forma* forma = &esfera;

    CHECK(forma->get_nome() == "esfera"); // Verificar que a função virtual retorna o nome correto da forma
    CHECK(forma->get_cor() == "amarelo"); // Verificar que a função virtual retorna a cor correta da forma

    Forma3D* forma3D = dynamic_cast<Forma3D*>(forma);
    CHECK(forma3D != nullptr); // Verificar se a conversão de ponteiro para Forma3D é bem-sucedida

    CHECK(abs(forma3D->get_volume() - 268.082) < 0.001); // Verificar que a função virtual da forma3D retorna o volume correto
}

TEST_CASE("13 - Acessando métodos específicos da classe Circulo") {
    Circulo circulo("azul", 5);
    CHECK(abs(circulo.get_area() - 78.5398) < 0.001); // Verificar cálculo correto da área
    CHECK(abs(circulo.get_perimetro() - 31.4159) < 0.001); // Verificar cálculo correto do perímetro
}

TEST_CASE("14 - Testando polimorfismo com Circulo") {
    Circulo circulo("vermelho", 3);
    Forma* forma = &circulo;

    CHECK(forma->get_nome() == "circulo"); // Verificar que a função virtual retorna o nome correto da forma
    CHECK(forma->get_cor() == "vermelho"); // Verificar que a função virtual retorna a cor correta da forma

    Forma2D* forma2D = dynamic_cast<Forma2D*>(forma);
    CHECK(forma2D != nullptr); // Verificar se a conversão de ponteiro para Forma2D é bem-sucedida

    CHECK(abs(forma2D->get_area() - 28.2743) < 0.001); // Verificar que a função virtual da forma2D retorna a área correta
    CHECK(abs(forma2D->get_perimetro() - 18.8495) < 0.001); // Verificar que a função virtual da forma2D retorna o perímetro correto
}

TEST_CASE("15 - Acessando métodos específicos da classe Cubo") {
    Cubo cubo("azul", 4);
    CHECK(cubo.get_volume() == 64); // Verificar cálculo correto do volume
}

TEST_CASE("16 - Testando polimorfismo com Cubo") {
    Cubo cubo("verde", 5);
    Forma* forma = &cubo;

    CHECK(forma->get_nome() == "cubo"); // Verificar que a função virtual retorna o nome correto da forma
    CHECK(forma->get_cor() == "verde"); // Verificar que a função virtual retorna a cor correta da forma

    Forma3D* forma3D = dynamic_cast<Forma3D*>(forma);
    CHECK(forma3D != nullptr); // Verificar se a conversão de ponteiro para Forma3D é bem-sucedida

    CHECK(forma3D->get_volume() == 125); // Verificar que a função virtual da forma3D retorna o volume correto
}

