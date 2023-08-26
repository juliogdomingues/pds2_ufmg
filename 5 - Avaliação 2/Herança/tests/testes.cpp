#include "doctest.h"

#include "destinationpackages.h"
#include "overnightpackage.h"
#include "package.h"
#include "twodaypackage.h"

#include <string>


TEST_CASE("01 - Testando o construtor sem parâmetros") {
    CHECK_NOTHROW(DestinationPackages()); //construtor com formato (peso, custo_por_quilo, nome, endereço)
}


TEST_CASE("02 - Testando a inserção de pacotes e o custo total por usuário") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Josias") == 15);
    CHECK(pacotes.custo_total("Maria") == 30);
    CHECK(pacotes.custo_total("Carlos") == 25);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("03 - Testando o cálculo de custo total de pacotes") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total() == 70);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("04 - Checando um custo nulo para uma chave não presente no map; e para um map vazio") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    DestinationPackages pacotes2;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Marcos") == 0);
    CHECK(pacotes2.custo_total()==0);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}


TEST_CASE("05 - Inserção de membros de classes derivadas e cálculo de custo polimorficamente") {
    
    Package *p1 = new OverNightPackage(2, 5, 7, "Maria", "Rio");
    Package *p2 = new OverNightPackage(3, 2, 1, "Paulo", "Juazeiro");
    Package *p3 = new TwoDayPackage(5, 2, 4, "Josias", "Juazeiro");
    Package *p4 = new TwoDayPackage(2, 5, 3, "Maria", "Juazeiro");
    Package *p5 = new Package(5, 7, "Paulo", "Juazeiro");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Josias") == 14);
    CHECK(pacotes.custo_total("Maria") == 37);
    CHECK(pacotes.custo_total("Paulo") == 44);
    CHECK(pacotes.custo_total() == 95);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}


TEST_CASE("06 - package.cpp") {
    Package *p1 = new Package(5, 7, "Paulo", "Juazeiro");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));

    CHECK(p1->get_nome() == "Paulo");
    CHECK(p1->get_peso() == 5);
    CHECK(p1->get_custo_por_quilo() == 7);
    CHECK(pacotes.custo_total() == 35);
    
    delete p1;

}

TEST_CASE("07 - twoday.cpp") {
    Package *p1 = new TwoDayPackage(5, 7, 8, "Paulo", "Juazeiro");

    // DestinationPackages pacotes;
    // CHECK_NOTHROW(pacotes.add_package(p1));

    CHECK(p1->get_nome() == "Paulo");
    CHECK(p1->get_peso() == 5);
    CHECK(p1->get_custo_por_quilo() == 7);
    CHECK(p1->calculate_cost() == 43);

    delete p1;

}

TEST_CASE("08 - overnight.cpp") {
    Package *p1 = new OverNightPackage(5, 7, 8, "Paulo", "Juazeiro");

    // DestinationPackages pacotes;
    // CHECK_NOTHROW(pacotes.add_package(p1));

    CHECK(p1->get_nome() == "Paulo");
    CHECK(p1->get_peso() == 5);
    CHECK(p1->get_custo_por_quilo() == 7);
    CHECK(p1->calculate_cost() == 75);

    delete p1;

}


TEST_CASE("9 - Testando a cópia de objetos DestinationPackages") {
    Package *p1 = new Package(2, 5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5, 5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4, 5, "Maria", "Alfeneiros");

    DestinationPackages pacotes1;
    pacotes1.add_package(p1);
    pacotes1.add_package(p2);
    pacotes1.add_package(p3);

    DestinationPackages pacotes2(pacotes1); // Fazendo uma cópia de pacotes1

    CHECK(pacotes1.custo_total() == pacotes2.custo_total());

    pacotes1.add_package(new Package(3, 2, "Paulo", "Juazeiro"));

    CHECK(pacotes1.custo_total() != pacotes2.custo_total());

    delete p1;
    delete p2;
    delete p3;
}

TEST_CASE("10 - Testando a atribuição de objetos DestinationPackages") {
    Package *p1 = new Package(2, 5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5, 5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4, 5, "Maria", "Alfeneiros");

    DestinationPackages pacotes1;
    pacotes1.add_package(p1);
    pacotes1.add_package(p2);
    pacotes1.add_package(p3);

    DestinationPackages pacotes2;
    pacotes2 = pacotes1; // Atribuição de pacotes1 para pacotes2

    CHECK(pacotes1.custo_total() == pacotes2.custo_total());

    pacotes1.add_package(new Package(3, 2, "Paulo", "Juazeiro"));

    CHECK(pacotes1.custo_total() != pacotes2.custo_total());

    delete p1;
    delete p2;
    delete p3;
}

TEST_CASE("11 - Testando cálculo de custo para pacote normal") {
    Package package(5, 3, "João Silva", "Rua Principal");
    CHECK(package.calculate_cost() == 15);
}

TEST_CASE("12 - Testando cálculo de custo para pacote noturno") {
    OverNightPackage overnightPackage(5, 3, 2, "Maria Santos", "Rua Secundária");
    CHECK(overnightPackage.calculate_cost() == 25);
}

TEST_CASE("13 - Testando cálculo de custo para pacote normal") {
    Package package(5, 3, "João Silva", "Rua Principal");
    CHECK(package.calculate_cost() == 15);
}

TEST_CASE("14 - Testando cálculo de custo para pacote noturno") {
    OverNightPackage overnightPackage(5, 3, 2, "Maria Santos", "Rua Secundária");
    CHECK(overnightPackage.calculate_cost() == 25);
}

TEST_CASE("15 - Testando cálculo de custo para pacote de dois dias") {
    TwoDayPackage twoDayPackage(5, 3, 10, "Carlos Pereira", "Avenida Central");
    CHECK(twoDayPackage.calculate_cost() == 25);
}

TEST_CASE("16 - Testando adição de pacotes por usuário") {
    Package* p1 = new Package(2, 5, "João Silva", "Rua Principal");
    Package* p2 = new Package(3, 4, "Maria Santos", "Rua Secundária");
    Package* p3 = new Package(4, 6, "João Silva", "Avenida Central");
    Package* p4 = new Package(5, 3, "Carlos Pereira", "Rua Principal");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("João Silva") == 34);
    CHECK(pacotes.custo_total("Maria Santos") == 12);
    CHECK(pacotes.custo_total("Carlos Pereira") == 15);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("17 - Testando cálculo de custo total para todos os pacotes") {
    Package* p1 = new Package(2, 5, "João Silva", "Rua Principal");
    Package* p2 = new Package(3, 4, "Maria Santos", "Rua Secundária");
    Package* p3 = new Package(4, 6, "João Silva", "Avenida Central");
    Package* p4 = new Package(5, 3, "Carlos Pereira", "Rua Principal");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total() == 61);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("18 - Testando cálculo de custo total para usuário não presente") {
    Package* p1 = new Package(2, 5, "João Silva", "Rua Principal");
    Package* p2 = new Package(3, 4, "Maria Santos", "Rua Secundária");
    Package* p3 = new Package(4, 6, "João Silva", "Avenida Central");
    Package* p4 = new Package(5, 3, "Carlos Pereira", "Rua Principal");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("Ana Oliveira") == 0);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("19 - Testando adição de pacotes de diferentes tipos") {
    Package* p1 = new Package(2, 5, "João Silva", "Rua Principal");
    OverNightPackage* p2 = new OverNightPackage(3, 4, 2, "Maria Santos", "Rua Secundária");
    TwoDayPackage* p3 = new TwoDayPackage(4, 6, 10, "João Silva", "Avenida Central");
    Package* p4 = new Package(5, 3, "Carlos Pereira", "Rua Principal");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("João Silva") == 44);
    CHECK(pacotes.custo_total("Maria Santos") == 18);
    CHECK(pacotes.custo_total("Carlos Pereira") == 15);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

