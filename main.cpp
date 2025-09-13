#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

struct WeatherRecord {
    int year;
    string city;
    double temperature;
};

class WeatherDataStorage {
private:
    vector<vector<double>> weather_data; // Rows = years, Columns = cities
    vector<string> cities;
    int start_year;
    const double SENTINEL = numeric_limits<double>::quiet_NaN();

    string toLower(const string &s) {
        string temp = s;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        return temp;
    }

public:
    WeatherDataStorage(const vector<string>& city_list, int start_year_val, int num_years)
        : cities(city_list), start_year(start_year_val) {
        weather_data.resize(num_years, vector<double>(cities.size(), SENTINEL));
    }

    void insert(const WeatherRecord& data) {
        int city_index = -1;
        string city_lower = toLower(data.city);

        for (size_t i = 0; i < cities.size(); ++i) {
            if (toLower(cities[i]) == city_lower) {
                city_index = i;
                break;
            }
        }

        int year_index = data.year - start_year;

        if (city_index != -1 && year_index >= 0 && (size_t)year_index < weather_data.size()) {
            weather_data[year_index][city_index] = data.temperature;
            cout << "Record inserted successfully.\n";
        } else {
            cout << "Could not insert record. City or year out of range.\n";
        }
    }

    void remove(const string& city, int year) {
        int city_index = -1;
        string city_lower = toLower(city);

        for (size_t i = 0; i < cities.size(); ++i) {
            if (toLower(cities[i]) == city_lower) {
                city_index = i;
                break;
            }
        }

        int year_index = year - start_year;

        if (city_index != -1 && year_index >= 0 && (size_t)year_index < weather_data.size()) {
            if (!isnan(weather_data[year_index][city_index])) {
                weather_data[year_index][city_index] = SENTINEL;
                cout << "Record deleted successfully.\n";
            } else {
                cout << "No record found to delete for this city/year.\n";
            }
        } else {
            cout << "Could not delete record. City or year out of range.\n";
        }
    }

    void retrieve(const string& city, int year) {
        int city_index = -1;
        string city_lower = toLower(city);

        for (size_t i = 0; i < cities.size(); ++i) {
            if (toLower(cities[i]) == city_lower) {
                city_index = i;
                break;
            }
        }

        int year_index = year - start_year;

        if (city_index != -1 && year_index >= 0 && (size_t)year_index < weather_data.size()) {
            double temp = weather_data[year_index][city_index];
            if (!isnan(temp)) {
                cout << "Temperature in " << cities[city_index] << " in " << year << ": " << temp << "°C\n";
            } else {
                cout << "No data available for " << cities[city_index] << " in " << year << ".\n";
            }
        } else {
            cout << "Invalid city or year.\n";
        }
    }

    void rowMajorAccess() {
        cout << "\n--- Row-Major Access ---\n";
        bool found_data = false;
        for (size_t year_idx = 0; year_idx < weather_data.size(); ++year_idx) {
            for (size_t city_idx = 0; city_idx < cities.size(); ++city_idx) {
                double temp = weather_data[year_idx][city_idx];
                if (!isnan(temp)) {
                    cout << "Year: " << (start_year + year_idx)
                         << ", City: " << cities[city_idx]
                         << ", Temp: " << temp << "°C\n";
                    found_data = true;
                }
            }
        }
        if (!found_data) cout << "No data to display.\n";
    }

    void columnMajorAccess() {
        cout << "\n--- Column-Major Access ---\n";
        bool found_data = false;
        for (size_t city_idx = 0; city_idx < cities.size(); ++city_idx) {
            for (size_t year_idx = 0; year_idx < weather_data.size(); ++year_idx) {
                double temp = weather_data[year_idx][city_idx];
                if (!isnan(temp)) {
                    cout << "City: " << cities[city_idx]
                         << ", Year: " << (start_year + year_idx)
                         << ", Temp: " << temp << "°C\n";
                    found_data = true;
                }
            }
        }
        if (!found_data) cout << "No data to display.\n";
    }
};

int main() {
    vector<string> city_list = {"Delhi", "Mumbai", "Kolkata", "Chennai"};
    WeatherDataStorage data_system(city_list, 2000, 26); // 2000-2025

    int choice;
    do {
        cout << "\nWeather Data Storage System\n";
        cout << "1. Insert a record\n";
        cout << "2. Delete a record\n";
        cout << "3. Retrieve a record\n";
        cout << "4. Display data (Row-Major)\n";
        cout << "5. Display data (Column-Major)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {
            case 1: {
                WeatherRecord rec;
                cout << "Enter year: "; cin >> rec.year; cin.ignore();
                cout << "Enter city: "; getline(cin, rec.city);
                cout << "Enter temperature: "; cin >> rec.temperature; cin.ignore();
                data_system.insert(rec);
                break;
            }
            case 2: {
                string city; int year;
                cout << "Enter city to delete: "; getline(cin, city);
                cout << "Enter year to delete: "; cin >> year; cin.ignore();
                data_system.remove(city, year);
                break;
            }
            case 3: {
                string city; int year;
                cout << "Enter city to retrieve: "; getline(cin, city);
                cout << "Enter year to retrieve: "; cin >> year; cin.ignore();
                data_system.retrieve(city, year);
                break;
            }
            case 4: data_system.rowMajorAccess(); break;
            case 5: data_system.columnMajorAccess(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 6);

    return 0;
}
