#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _prices(other._prices) {}


BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _prices = other._prices;
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	bool firstLine = true;
	std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    while (std::getline(file, line))
	{
		if (firstLine)
		{
            firstLine = false;
            continue;
        }
        std::istringstream iss(line);
        std::string date;
        float price;

        if (std::getline(iss, date, ',') && (iss >> price))
            _prices[date] = price;
		else
            std::cerr << "Warning: invalid line in database: " << line << std::endl;
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string& inputFile)
{
	std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file.");

    std::string line;
    while (std::getline(file, line))
	{
        try
		{
            std::istringstream iss(line);
            std::string date, valueStr;

            if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
			{
                char* end;
				float value = std::strtof(valueStr.c_str(), &end);
				if (*end != '\0')
				    throw std::invalid_argument("Error: bad input => " + line);
				if (value < 0 || value > 1000)
				    throw std::invalid_argument("Error: value out of range (0 to 1000 expected).");
                float rate = getExchangeRate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            }
			else
                throw std::invalid_argument("Error: bad input => " + line);
        }
		catch (const std::exception& e)
		{
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date)
{
    std::map<std::string, float>::iterator it = _prices.lower_bound(date);
    if (it == _prices.end() || it->first != date)
    {
        if (it == _prices.begin())
            throw std::invalid_argument("Error: no earlier date available.");
        --it;
    }
    return it->second;
}