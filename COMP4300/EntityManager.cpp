#include "EntityManager.h"

EntityManager::EntityManager()
{
}

void EntityManager::update()
{
    for (auto e : m_toAdd)
    {
        m_entities.push_back(e);
        m_entityMap[e->m_tag].push_back(e);
    }

    m_toAdd.clear();

    removeDeadEntities(m_entities);

    for (auto& e : m_entityMap) {
        removeDeadEntities(e.second);
    }
    //for (auto e : m_entities)
    //{

    //    if (e->m_tag.compare("player") == 0 && !e->m_active)
    //    {
    //        std::cout << "destroy player" << "\n";
    //        m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), e), m_entities.end());
    //        m_entityMap[e->m_tag].erase(std::remove(m_entityMap[e->m_tag].begin(), m_entityMap[e->m_tag].end(), e), m_entityMap[e->m_tag].end());
    //        return;
    //    }

    //    if (!e->m_active)
    //    {
    //        //std::cout << "delete:" << e->m_tag << "\n";
    //        m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), e), m_entities.end());
    //        m_entityMap[e->m_tag].erase(std::remove(m_entityMap[e->m_tag].begin(), m_entityMap[e->m_tag].end(), e), m_entityMap[e->m_tag].end());
    //        return;
    //        //m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), e),m_entities.end());
    //       
    //    }

    //    
    //}

    

    
   
}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
    auto it = remove_if(vec.begin(), vec.end(), [](const EntityPtr& e) {return e->isActive() == false; });

    vec.erase(it, vec.end());
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
    //auto e = std::make_shared<Entity>(tag, m_totalEntities++);
    auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++));
   
    
    m_toAdd.push_back(e);
    //m_entities.push_back(e);
    //m_entityMap[tag].push_back(e);
    return e;
}

EntityVec& EntityManager::getEntities()
{
    return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
    // TODO: insert return statement here
    return m_entityMap[tag];
}

EntityMap& EntityManager::getEntityMap(const std::string& tag)
{
    // TODO: insert return statement here
    return m_entityMap;
}
