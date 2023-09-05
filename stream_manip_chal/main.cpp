#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

struct Country {
    std::string name;
    std::vector <City> cities;
};

struct Tours {
    std::string title;
    std::vector <Country> countries;
};

int main() {
    Tours tours {
        "Tour Ticket Prices from Miami", {
            {
                "Colombia", {
                    {"Bogota", 8778000, 400.98}, 
                    {"Cali", 2401000, 424.12}, 
                    {"Medellin", 2464000, 350.98}, 
                    {"Cartagena", 972000, 345.34} 
                }
            }, {
                "Brazil", {
                    {"Rio De Janiero", 13500000, 567.45}, 
                    {"Sao Paulo", 11310000, 975.45}, 
                    {"Salvador", 18234000, 855.99}
                }
            }, {
                "Chile", {
                    {"Valdivia", 260000, 569.12},
                    {"Santiago", 7040000, 520.00}
                }
            }, {
                "Argentina", {
                    { "Buenos Aires", 3010000, 723.77}
                }
            }
        }
    };
    
    const int total_width {70};
    const int field1_width {20};
    const int field2_width {15};
    int title_length = tours.title.length();
    const int field_width {(total_width-title_length)/2};

    std::cout<<'\n'<<std::setw(field_width)<<' '<<tours.title<<std::endl;

    std::cout<<std::setw(field_width)<<' '<<std::setw(title_length)<<std::setfill('-')<<'*'<<std::endl<<std::endl;

    std::cout<<std::setfill(' ')<<std::left;
    std::cout<<std::setw(field1_width)<<"Country"
             <<std::setw(field1_width)<<"City"
             <<std::right
             <<std::setw(field2_width)<<"Population"
             <<std::setw(field2_width)<<"Price"
             <<std::endl;

    std::cout<<std::setw(total_width)<<std::setfill('-')<<"*"<<std::endl<<std::endl;

    for(auto country : tours.countries){
        std::cout<<std::setfill(' ')<<std::left;
        std::cout<<std::setw(field1_width)<< country.name;

        std::cout<<std::setprecision(2)<<std::fixed;
        for(auto city : country.cities) {
            std::cout<<std::setw(field1_width)<<city.name
                     <<std::right
                     <<std::setw(field2_width)<<city.population
                     <<std::setw(field2_width)<<city.cost
                     <<std::endl;
            std::cout<<std::setw(field1_width)<<' '<<std::left;
            
        }
        std::cout<<std::endl;
    }

    std::cout << std::setw(total_width)<<std::right << std::setfill('-')<<'*'<<std::endl<<std::endl;


    std::cout<<std::setfill(' ');
    for(Country country:tours.countries) {
        for(size_t i=0; i<country.cities.size();i++) {
            std::cout << std::setw(field1_width) << std::left << ((i==0)?country.name:"")
                      << std::setw(field1_width) << country.cities.at(i).name
                      << std::setw(field2_width) << std::right << country.cities.at(i).population
                      << std::setw(field2_width) << country.cities.at(i).cost
                      << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl<< std::endl;

    return 0;
}