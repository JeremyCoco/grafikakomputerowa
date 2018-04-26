using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Produkt> listaProduktow = new List<Produkt>()
            {
                new Produkt
                {
                    id = 1,
                    id_kat = 1,
                    ilosc = 200,
                    nazwa = "szafa"
                },
                 new Produkt
                {
                    id = 2,
                    id_kat = 1,
                    ilosc = 20,
                    nazwa = "fotel"
                },
                 new Produkt
                {
                    id = 3,
                    id_kat = 2,
                    ilosc = 120,
                    nazwa = "dysk twardy"
                },
                 new Produkt
                {
                    id = 4,
                    id_kat = 1,
                    ilosc = 10,
                    nazwa = "krz12-321eslo"
                }
            };

            List<Kategoria> listaKategorii = new List<Kategoria>()
            {
                new Kategoria
                {
                    id = 1,
                    nazwa_kat = "meble"
                },
                 new Kategoria
                {
                    id = 2,
                    nazwa_kat = "sprzet"
                }
            };

            var najwiecejProdukt = listaProduktow.Where(produkty => produkty.ilosc >= 100).Select(produkty => produkty);

            foreach (Produkt item in najwiecejProdukt)
            {
                Console.WriteLine(item.nazwa);
            }

            var naS = listaProduktow.Where(x => x.nazwa.StartsWith("s")).Select(X => X);
            foreach (Produkt item in naS)
            {
                Console.WriteLine(item.nazwa);
            }

            Regex poczta = new Regex(@"\d{2}-\d{3}");

            var kod = listaProduktow.Where(x => poczta.IsMatch(x.nazwa.ToString())).Select(x => x);

            foreach (Produkt item in kod)
            {
                Console.WriteLine(item.nazwa);
            }

            var first = listaProduktow.Join(listaKategorii, a => a.id_kat, b => b.id, (a, b) => new { a.nazwa, b.nazwa_kat }).Take(3);

            foreach (var item in first)
            {
                Console.WriteLine(item);
            }

        }
    }
}
