/**
 * 
 * REPOSITORIO DE GITHUB: https://github.com/DGarGlez/PR05-SSI-ULL-DGarGlez.git
 * 
 */
#include <iostream>
#include <cstdint>
#include <bitset>

// Multiplicación en AES con módulo x^8 + x^4 + x^3 + x + 1 (0x1B)
/**
 * @brief Multiplicación de dos bytes en AES
 * @param a Primer byte
 * @param b Segundo byte
 * @return Resultado de la multiplicación en AES
 */
uint8_t multiplyAES(uint8_t a, uint8_t b) {
    uint8_t result = 0;
    uint8_t mod = 0x1B; // Polinomio irreducible para AES
    
    for (int i = 0; i < 8; i++) {   // Iterar sobre los 8 bits de b
        if (b & 1) {// Si el bit menos significativo de b es 1
            result ^= a;    // Hacer XOR con a
        }
        bool msb = (a & 0x80); // Guardar el bit más significativo de a
        a <<= 1;    // Desplazar a un bit a la izquierda
        if (msb) {  // Si el bit más significativo de a era 1
            a ^= mod;   // Hacer XOR con el polinomio irreducible
        }
        b >>= 1;    // Desplazar b un bit a la derecha
    }
    return result;
}

// Multiplicación en SNOW 3G con módulo x^8 + x^7 + x^5 + x^3 + 1 (0xA9)
/**
 * @brief Multiplicación de dos bytes en SNOW 3G
 * @param a Primer byte
 * @param b Segundo byte
 * @return Resultado de la multiplicación en SNOW 3G
 */
uint8_t multiplySNOW3G(uint8_t a, uint8_t b) {
    uint8_t result = 0;
    uint8_t mod = 0xA9; // Polinomio irreducible para SNOW 3G
    
    for (int i = 0; i < 8; i++) {   // Iterar sobre los 8 bits de b
        if (b & 1) {    // Si el bit menos significativo de b es 1
            result ^= a;    // Hacer XOR con a
        }
        bool msb = (a & 0x80);  // Guardar el bit más significativo de a
        a <<= 1;    // Desplazar a un bit a la izquierda
        if (msb) {  // Si el bit más significativo de a era 1
            a ^= mod;   // Hacer XOR con el polinomio irreducible
        }
        b >>= 1;    // Desplazar b un bit a la derecha
    }
    return result;
}
/**
 * @brief Función principal
 * @return 0 si el programa termina correctamente
 * @return 1 si el programa termina con errores
 */
int main() {
    int a, b;
    std::string algorithm;
    
    std::cout << "Ingrese el primer byte en decimal: ";
    std::cin >> a;
    
    std::cout << "Ingrese el segundo byte en decimal: ";
    std::cin >> b;
    
    std::cout << "Ingrese el algoritmo (AES o SNOW3G): ";
    std::cin >> algorithm;
    
    uint8_t byteA = static_cast<uint8_t>(a);    // Convertir a byte
    uint8_t byteB = static_cast<uint8_t>(b);    // Convertir a byte
    uint8_t result;
    
    if (algorithm == "AES") {
        result = multiplyAES(byteA, byteB);
    } else if (algorithm == "SNOW3G") {
        result = multiplySNOW3G(byteA, byteB);
    } else {
        std::cerr << "Algoritmo no reconocido." << std::endl;
        return 1;
    }
    
    std::cout << "Primer byte: " << std::bitset<8>(byteA) << std::endl;
    std::cout << "Segundo byte: " << std::bitset<8>(byteB) << std::endl;
    std::cout << "Byte Algoritmo: " << std::bitset<8>(algorithm == "AES" ? 0x1B : 0xA9) << std::endl;
    std::cout << "Multiplicación: " << std::bitset<8>(result) << std::endl;
    
    return 0;
}