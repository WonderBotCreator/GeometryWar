#include "Assignment2.h"
#include <random>


void Assignment2::init()
{
	m_running = true;
	m_window.create(sf::VideoMode(1280, 720), "Assignment 2");
	m_window.setFramerateLimit(60);

	ImGui::SFML::Init(m_window);

	clock2.restart();

	enableRender = true;
	enableUserInput = true;
	enableSpawnEnemy = true;
	enableCollision = true;

	if (!m_font.loadFromFile("fonts/roboto.ttf"))
	{
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	m_text = sf::Text("score: "+ std::to_string(m_score), m_font, 24);
	m_text.setPosition(20, m_text.getCharacterSize());

	spawnPlayer();
	//sEnemySpawner();
}

void Assignment2::spawnPlayer()
{
	auto entity = m_entities.addEntity("player");
	entity->cTransform = std::make_shared<CTransform>(Vec2(1280.0f/2.f, 720.f/2.f), Vec2(0.0f, 0.0f), 0.0f);
	entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);
	entity->cInput = std::make_shared<CInput>();
	
	m_player = entity;
}

void Assignment2::sEnemySpawner()
{

	if (!enableSpawnEnemy)
	{
		sf::Time time1 = clock2.getElapsedTime();
		target_time = time1.asSeconds();
		return;
	}
	

	sf::Time time1 = clock2.getElapsedTime();
	

	int currentTime = time1.asSeconds();

	if (currentTime  >= target_time)
	{
		

		

		//std::cout << randomPosX << ":" << randomPosY << "\n";

		for (int i = 0; i < m_spawnEnemyNumber; i++)
		{
			std::random_device engine;
			using dist_params = typename std::uniform_int_distribution<int>::param_type;


			std::uniform_int_distribution<int> sideX(0, 1);
			std::uniform_int_distribution<int> sideY(0, 1);
			std::uniform_int_distribution<int> color(0, 255);

			int sideXRand = sideX(engine);
			int sideYRand = sideY(engine);

			int maxX = sideXRand == 0 ? m_window.getSize().x / 2 - 60 : m_window.getSize().x - 45;
			int minX = sideXRand == 0 ? 45 : (m_window.getSize().x / 2 + 60);
			int maxY = sideYRand == 0 ? m_window.getSize().y / 2 - 60 : m_window.getSize().y - 45;
			int minY = sideYRand == 0 ? 45 : (m_window.getSize().y / 2 + 60);


			std::uniform_int_distribution<int> distX(minX, maxX);
			std::uniform_int_distribution<int> distY(minY, maxY);

			std::uniform_int_distribution<int> point(3, 6);


			int randomPosX = distX(engine);
			int randomPosY = distY(engine);

			auto enemyEntity = m_entities.addEntity("enemy");
			enemyEntity->cTransform = std::make_shared<CTransform>(Vec2(randomPosX, randomPosY), Vec2(1, 1), 0);
			enemyEntity->cShape = std::make_shared<CShape>(32.0f, point(engine), sf::Color(color(engine), color(engine), color(engine)), sf::Color(255, 255, 255), 4.f);
		}
		


		target_time += 5;
	}


}

void Assignment2::sBulletSpawner()
{
	std::cout << "fire" << "\n";
	
		//std::cout << "create bullet" << "\n";
		auto bulletEntity = m_entities.addEntity("bullet");
		Vec2 target(mousePosX - m_player->cTransform->pos.x, mousePosY - m_player->cTransform->pos.y);

		float vx = target.x / target.dist(Vec2(0, 0));
		float vy = target.y / target.dist(Vec2(0, 0));

		float bulletSpeed = 4.0f;

		//float vx = target.dist(Vec2(0,0)) * cosf(atan2f(mousePosY-m_player->cTransform->pos.y, mousePosX - m_player->cTransform->pos.x));
		//float vy = (mousePosX - m_player->cTransform->pos.x) * cosf(atan2f(mousePosY - m_player->cTransform->pos.y, mousePosX - m_player->cTransform->pos.x));
		bulletEntity->cTransform = std::make_shared<CTransform>(Vec2(m_player->cTransform->pos.x, m_player->cTransform->pos.y), Vec2(4.f*vx, 4.f*vy), 0.0f);
		bulletEntity->cShape = std::make_shared<CShape>(16.0f, 8, sf::Color(255, 255, 255,255), sf::Color(0, 0, 0), 1.0f);
		//bulletEntity->time = std::make_shared<sf::Time>(clock2.getElapsedTime());
		sf::Time time1 = clock2.getElapsedTime();
		bulletEntity->startTime = time1.asSeconds();
	
}

void Assignment2::sMovement()
{

	//Enemy
	for (auto enemy : m_entities.getEntities("enemy"))
	{

		if (enemy->cTransform->pos.x + enemy->cShape->circle.getRadius() > m_window.getSize().x)
		{
			enemy->cTransform->velocity.x = -1.f;
		}


		
		enemy->cTransform->pos.x += enemy->cTransform->velocity.x;
		enemy->cTransform->pos.y += enemy->cTransform->velocity.y;
	}


	//Bullet
	for (auto bullet : m_entities.getEntities("bullet"))
	{
		bullet->cTransform->pos.x += bullet->cTransform->velocity.x;
		bullet->cTransform->pos.y += bullet->cTransform->velocity.y;
	}


	//Player

	if ((m_player->cTransform->pos.x + m_player->cShape->circle.getRadius()) > m_window.getSize().x)
	{
		m_player->cTransform->pos.x = m_window.getSize().x- m_player->cShape->circle.getRadius();
		return;
	}

	if ((m_player->cTransform->pos.x - m_player->cShape->circle.getRadius()) < 0)
	{
		m_player->cTransform->pos.x = m_player->cShape->circle.getRadius()+1;
		return;
	}

	if ((m_player->cTransform->pos.y + m_player->cShape->circle.getRadius()) > m_window.getSize().y)
	{
		m_player->cTransform->pos.y = m_window.getSize().y - m_player->cShape->circle.getRadius();
		return;
	}

	if ((m_player->cTransform->pos.y - m_player->cShape->circle.getRadius()) < 0)
	{
		m_player->cTransform->pos.y = m_player->cShape->circle.getRadius() + 1;
		return;
	}
	
	if(m_player->cTransform->velocity.x != 0 && m_player->cTransform->velocity.y != 0)
	{

		float vx = m_player->cTransform->velocity.x * cosf(45.0f * M_PI / 180.0f);
		float vy = m_player->cTransform->velocity.y * sinf(45.0f * M_PI / 180.0f);

		//Vec2 v(vx, vy);
		//Vec2 v2(0, 0);
		//std::cout << v.dist(v2) << "\n";
		//std::cout << v.x << ":" << v.y << "\n";
		m_player->cTransform->pos.x += vx ;
		m_player->cTransform->pos.y += vy;
	}
	else 
	{
		//std::cout << "not active" << "\n";
		m_player->cTransform->pos.x += m_player->cTransform->velocity.x;
		m_player->cTransform->pos.y += m_player->cTransform->velocity.y;
	}

	
}

void Assignment2::sCollision()
{

	if (!enableCollision)
	{
		for (auto enemy : m_entities.getEntities("enemy"))
		{
			if (enemy->cTransform->pos.x - enemy->cShape->circle.getRadius() > m_window.getSize().x
				|| enemy->cTransform->pos.x + enemy->cShape->circle.getRadius() < 0
				|| enemy->cTransform->pos.y - enemy->cShape->circle.getRadius() > m_window.getSize().y
				|| enemy->cTransform->pos.y + enemy->cShape->circle.getRadius() < 0)
			{
				enemy->destroy();
			}
		}

		return;
	}

	for (auto enemy : m_entities.getEntities("enemy"))
	{

		if (enemy->cTransform->pos.x + enemy->cShape->circle.getRadius() >= m_window.getSize().x)
		{
			enemy->cTransform->velocity.x = -1.f;
		}

		if (enemy->cTransform->pos.x - enemy->cShape->circle.getRadius() <= 0)
		{
			enemy->cTransform->velocity.x = 1.f;
		}

		if (enemy->cTransform->pos.y + enemy->cShape->circle.getRadius() >= m_window.getSize().y)
		{
			enemy->cTransform->velocity.y = -1.f;
		}

		if (enemy->cTransform->pos.y - enemy->cShape->circle.getRadius() <= 0)
		{
			enemy->cTransform->velocity.y = 1.f;
		}



		if (enemy->cShape->circle.getRadius() < 10)
		{
			sf::Time time1 = clock2.getElapsedTime();

			if (enemy->startTime + enemy->targetTime <= time1.asSeconds())
			{
				//std::cout << time1.asSeconds() - enemy->startTime << "\n";
				enemy->destroy();
			}
		}

	}

	for (auto bullet : m_entities.getEntities("bullet"))
	{
		//if bullet is out of screen then delete it
		if (bullet->cTransform->pos.x - bullet->cShape->circle.getRadius() > m_window.getSize().x
			|| bullet->cTransform->pos.x + bullet->cShape->circle.getRadius() < 0
			|| bullet->cTransform->pos.y - bullet->cShape->circle.getRadius() > m_window.getSize().y
			|| bullet->cTransform->pos.y + bullet->cShape->circle.getRadius() < 0)
		{
			bullet->destroy();
		}


		//if bullet is time out then delete it
		sf::Time time1 = clock2.getElapsedTime();

		if (bullet->startTime + bullet->targetTime <= time1.asSeconds())
		{
			//std::cout <<  time1.asSeconds() - bullet->startTime  << "\n";
			bullet->destroy();
		}
	}



	
	//enemy hit player
	for (auto enemy : m_entities.getEntities("enemy"))
	{
		float dx = m_player->cTransform->pos.x - enemy->cTransform->pos.x;
		float dy = m_player->cTransform->pos.y - enemy->cTransform->pos.y;

		float d = sqrtf(dx * dx + dy * dy);


		//std::cout << d << ":" << m_player->cShape->circle.getRadius()+ enemy->cShape->circle.getRadius() << "\n";

		if (m_player->isActive() && d <= m_player->cShape->circle.getRadius() + enemy->cShape->circle.getRadius())
		{
			
			m_score = 0;
			m_player->destroy();
			spawnPlayer();
			//m_player->cTransform->pos.x = m_window.getSize().x / 2;
			//m_player->cTransform->pos.y = m_window.getSize().y / 2;
			
			//spawnPlayer();
			
			if (enemy->cShape->circle.getRadius() > 8)
			{
				float dirStep = 360.f / enemy->cShape->circle.getPointCount();
				float dir = 0;

				for (int i = 0; i < enemy->cShape->circle.getPointCount(); i++)
				{
					std::cout << "create small enemy" << "\n";
					dir += dirStep;

					float vx = cosf(dir * M_PI / 180.f);
					float vy = sinf(dir * M_PI / 180.f);

					auto smallEnemy = m_entities.addEntity("enemy");
					smallEnemy->cTransform = std::make_shared<CTransform>(Vec2(enemy->cTransform->pos.x, enemy->cTransform->pos.y), Vec2(vx, vy), 0.0f);
					smallEnemy->cShape = std::make_shared<CShape>(8.0f, enemy->cShape->circle.getPointCount(), enemy->cShape->circle.getFillColor(), enemy->cShape->circle.getOutlineColor(), 1.0f);
					sf::Time time1 = clock2.getElapsedTime();
					smallEnemy->startTime = time1.asSeconds();
				}
			}
			
			enemy->destroy();
			
		}

	}


	
	
	//bullet hit enemy
	for (auto bullet : m_entities.getEntities("bullet"))
	{



		for (auto enemy : m_entities.getEntities("enemy"))
		{
			float dx = bullet->cTransform->pos.x - enemy->cTransform->pos.x;
			float dy = bullet->cTransform->pos.y - enemy->cTransform->pos.y;

			float d = sqrtf(dx * dx + dy * dy);

			if (enemy->isActive() && d <= enemy->cShape->circle.getRadius() + bullet->cShape->circle.getRadius())
			{
				
				bullet->destroy();


				enemy->destroy();
				if (enemy->cShape->circle.getRadius() > 10)
				{
					m_score+= enemy->cShape->circle.getPointCount()*100;
					float dirStep = 360.f / enemy->cShape->circle.getPointCount();
					float dir = 0;

					
					for (int i = 0; i < enemy->cShape->circle.getPointCount(); i++)
					{
						
						
						dir += dirStep;

						float vx = cosf(dir * M_PI / 180.f);
						float vy = sinf(dir * M_PI / 180.f);

						auto smallEnemy = m_entities.addEntity("enemy");
						smallEnemy->cTransform = std::make_shared<CTransform>(Vec2(enemy->cTransform->pos.x, enemy->cTransform->pos.y), Vec2(vx, vy), 0.0f);
						smallEnemy->cShape = std::make_shared<CShape>(8.0f, enemy->cShape->circle.getPointCount() , enemy->cShape->circle.getFillColor(), enemy->cShape->circle.getOutlineColor(), 1.0f);
						sf::Time time1 = clock2.getElapsedTime();
						smallEnemy->startTime = time1.asSeconds();
					}
				}
				
				
			}
		}
	}
}

void Assignment2::sUserInput()
{

	if (!enableUserInput)
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(m_window, event);
			if (event.type == sf::Event::Closed)
			{
				m_running = false;
				m_window.close();
			}
		}

		return;
	}

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(m_window, event);
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
			m_window.close();
		}

		/*if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				m_player->cTransform->velocity.y = -2.0f;
				break;
			case sf::Keyboard::S:
				m_player->cTransform->velocity.y = 2.0f;
				break;
			case sf::Keyboard::A:
				m_player->cTransform->velocity.x = -2.0f;
				break;
			case sf::Keyboard::D:
				m_player->cTransform->velocity.x = 2.0f;
				break;
			default:
				m_player->cTransform->velocity.x = 0;
				m_player->cTransform->velocity.y = 0;
				break;
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				m_player->cTransform->velocity.y = 0.0f;
				break;
			case sf::Keyboard::S:
				m_player->cTransform->velocity.y = 0.0f;
				break;
			case sf::Keyboard::A:
				m_player->cTransform->velocity.x = 0.0f;
				break;
			case sf::Keyboard::D:
				m_player->cTransform->velocity.x = 0.0f;
				break;
			default:
				m_player->cTransform->velocity.x = 0;
				m_player->cTransform->velocity.y = 0;
				break;
			}
		}*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player->cTransform->velocity.y = -2.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player->cTransform->velocity.y = 2.0f;
	}
	else
	{
		m_player->cTransform->velocity.y = 0.0f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player->cTransform->velocity.x = 2.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player->cTransform->velocity.x = -2.0f;
	}
	else
	{
		m_player->cTransform->velocity.x = 0.0f;
	}

	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (!isMouseAlreadyPressed)
		{
			isMouseAlreadyPressed = true;
			sf::Vector2i globalPosition = sf::Mouse::getPosition(m_window);
			mousePosX = globalPosition.x;
			mousePosY = globalPosition.y;
			
			//std::cout << globalPosition.x << ":" << globalPosition.y << "\n";
			sBulletSpawner();
			//std::cout << m_entities.getEntities("bullet").size() << "\n";
		}
		
	}
	else
	{
		isMouseAlreadyPressed = false;
	}
}

void Assignment2::sGUI()
{
	ImGui::Begin("Window title");
	ImGui::Text("Window text!");
	ImGui::Checkbox("show GUI", &enableRender);
	ImGui::Checkbox("enable user input", &enableUserInput);
	ImGui::Checkbox("enable spawn enemy", &enableSpawnEnemy);
	ImGui::SliderInt("Sides", &m_spawnEnemyNumber, 1, 20);
	//ImGui::InputText("Enemy", (char*)m_spawnEnemyNumber.c_str(), 255);
	ImGui::Checkbox("enable collision", &enableCollision);
	ImGui::End();
}

void Assignment2::sRender()
{
	if (!enableRender)
	{
		m_window.clear();
		ImGui::SFML::Render(m_window);
		m_window.display();
		return;
	}
	//ImGui::SFML::Update(m_window, m_deltaClock.restart());

	m_window.clear();
	sf::Time time1 = clock2.getElapsedTime();
	for (auto bullet : m_entities.getEntities("bullet"))
	{
		bullet->cShape->circle.setPosition(bullet->cTransform->pos.x, bullet->cTransform->pos.y);
		bullet->cTransform->angle += 1.0f;
		bullet->cShape->circle.setRotation(bullet->cTransform->angle);
		//sf::Time time1 = clock2.getElapsedTime();
		//std::cout << 255*(time1.asSeconds() - bullet->startTime )/ bullet->targetTime << "\n";
		bullet->cShape->circle.setFillColor(sf::Color(255, 255, 255, 256-(255 * (time1.asSeconds() - bullet->startTime) / bullet->targetTime)));
	}

	for (auto enemy : m_entities.getEntities("enemy"))
	{
		enemy->cShape->circle.setPosition(enemy->cTransform->pos.x, enemy->cTransform->pos.y);
		enemy->cTransform->angle += 1.0f;
		enemy->cShape->circle.setRotation(enemy->cTransform->angle);

		if (enemy->cShape->circle.getRadius() < 30)
		{
			enemy->cShape->circle.setFillColor(sf::Color(enemy->cShape->circle.getFillColor().r, enemy->cShape->circle.getFillColor().g, enemy->cShape->circle.getFillColor().b, 256 - (200 * (time1.asSeconds() - enemy->startTime) / enemy->targetTime)));
			enemy->cShape->circle.setOutlineColor(sf::Color(enemy->cShape->circle.getOutlineColor().r, enemy->cShape->circle.getOutlineColor().g, enemy->cShape->circle.getOutlineColor().b, 256 - (200 * (time1.asSeconds() - enemy->startTime) / enemy->targetTime)));
		}
	}

	m_player->cShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

	m_player->cTransform->angle += 1.0f;
	m_player->cShape->circle.setRotation(m_player->cTransform->angle);


	for (auto bullet : m_entities.getEntities("bullet"))
	{
		m_window.draw(bullet->cShape->circle);
	}

	for (auto enemy : m_entities.getEntities("enemy"))
	{
		m_window.draw(enemy->cShape->circle);
	}
	

	m_window.draw(m_player->cShape->circle);

	m_text.setString("score: " + std::to_string(m_score));
	m_window.draw(m_text);

	ImGui::SFML::Render(m_window);
	m_window.display();
}

Assignment2::Assignment2()
{
	init();
}

void Assignment2::run()
{
	while (m_window.isOpen())
	{
		
		m_entities.update();

		sUserInput();
		ImGui::SFML::Update(m_window, m_deltaClock.restart());
		sCollision();
		//std::cout << m_entities.getEntities("enemy").size() << "\n";
		sEnemySpawner();
		sMovement();
		sGUI();
		sRender();
		
		//sf::Time time1 = clock2.getElapsedTime();
		//std::cout << time1.asSeconds() << "\n";

		m_currentFrame++;
	}
}
