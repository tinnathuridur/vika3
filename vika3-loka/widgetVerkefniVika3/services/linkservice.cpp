#include "linkservice.h"

#include <string>

using namespace std;

LinkService::LinkService()
{

}

bool LinkService::addLink(string scientistId, string computerId)
{
    return linkRepo.addLink(scientistId, computerId);
}

bool LinkService::deleteLink(string scientistId, string computerId)
{
    return linkRepo.deleteLink(scientistId, computerId);
}
