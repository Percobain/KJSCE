weather_data = { 
    "Delhi": {
        "9-11-2018": 45,
    },
    "Bangalore": {
        "9-11-2018": 24,
    },
    "Mumbai": {
        "9-12-2018": 28,
    },
    "Chennai": {
        "9-01-2018": 38,
    }
}

def get_temperature(city, date):
    return weather_data.get(city, {}).get(date, "Data not available")

def max_temperature(city):
    if city in weather_data:
        return max(weather_data[city].values()) 
    return "No data available"

def count_entries():
    return sum(len(dates) for dates in weather_data.values())


def delete_entry(city, date):
    if city in weather_data and date in weather_data[city]: 
        del weather_data[city][date]
        return f"Entry for {city} on {date} deleted." 
    return "Entry not found."

def delete_all_entries(city): 
    if city in weather_data:
        del weather_data[city]
        return f"All entries for {city} deleted." 
    return "City not found."


print("Temperature in Delhi on 9-11-2018:", get_temperature("Delhi", "9-11- 2018"))
print("Max temperature recorded in Chennai in 2018:", max_temperature("Chennai"))
print("Number of entries in 2018:", count_entries())
print(delete_entry("Mumbai", "9-11-2018"))
print(delete_all_entries("Mumbai"))
print("Updated data:", weather_data)

