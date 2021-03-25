#include <ctime>
#include <chrono>
#include <fstream>

int main()
{
    auto inicio = std::chrono::system_clock::now ();
    auto fin = std::chrono::system_clock::now ();
    std::chrono::duration <double> elapsed_seconds = fin - inicio;
    std::time_t end_time = std::chrono::system_clock::to_time_t ( fin );
    std::ofstream Archivo;
    Archivo.open ( "C:\\Users\\enri9\\Documents\\Archivo.txt", std::ios::app ) ;
    Archivo << std::ctime ( &end_time );
    Archivo.close ();
    return 0;
}