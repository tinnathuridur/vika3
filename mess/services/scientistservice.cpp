#include "services/scientistservice.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService()
{

}

std::vector<Scientist> ScientistService::getAllScientists()
{
    return scientistRepo.getAllScientists();
}

std::vector<Scientist> ScientistService::searchForScientists(string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}

bool ScientistService::deleteScientist(Scientist scientist)
{
    return scientistRepo.deleteScientist(scientist);
}

