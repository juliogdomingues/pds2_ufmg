Introdução

O mundo das formas é muito rico. Crie uma interface (em C++ uma classe abstract apenas com métodos virtuais = 0) chamada de Forma. 

Descrição

A interface mais abstrata, Forma, deve ter dois métodos: std::string get_cor() e std::string get_nome(). A mesma tem duas sub-interfaces: Forma2D e Forma3D. A primeira, deve conter os métodos double get_area() e double get_perimetro(). A segunda tem um único método double get_volume(). Implemente as classes: Quadrado, Circulo, Triangulo, Esfera e Cubo. Implemente os métodos: double get_area(), double get_perimetro() e double get_volume().
