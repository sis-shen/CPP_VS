#pragma once


//#include <iostream>
//#include <string>
//#include <memory>
//class Fruit {//水果的抽象类
//public:
//	Fruit() {}
//	virtual void show() = 0;
//};
//
//class Apple : public Fruit {//苹果类
//public:
//	Apple() {}
//	virtual void show() {
//		std::cout << "我是⼀个苹果" << std::endl;
//	}
//};
//class Banana : public Fruit {//香蕉类
//public:
//	Banana() {}
//	virtual void show() {
//		std::cout << "我是⼀个⾹蕉" << std::endl;
//	}
//};
//class FruitFactory {//水果工厂类,能生茶哪些水果由名字和内部代码决定
//public:
//	//当前代码只能生产苹果或香蕉
//	static std::shared_ptr<Fruit> create(const std::string& name) {
//		if (name == "苹果") {
//			return std::make_shared<Apple>();
//		}
//		else if (name == "⾹蕉") {
//			return std::make_shared<Banana>();
//		}
//		return std::shared_ptr<Fruit>();
//	}
//};
//int main()
//{
//	std::shared_ptr<Fruit> fruit = FruitFactory::create("苹果");
//	fruit->show();
//	fruit = FruitFactory::create("⾹蕉");
//	fruit->show();
//	return 0;
//}
//#include <iostream>
//#include <memory>
//#include <string>
//
//class Fruit {
//public:
//	Fruit() {}
//	virtual void show() = 0;
//};
//class Apple : public Fruit {
//public:
//	Apple() {}
//	virtual void show() {
//		std::cout << "我是⼀个苹果" << std::endl;
//	}
//private:
//	std::string _color;
//};
//class Banana : public Fruit {
//public:
//	Banana() {}
//	virtual void show() {
//		std::cout << "我是⼀个⾹蕉" << std::endl;
//	}
//};
//class FruitFactory {
//public:
//	virtual std::shared_ptr<Fruit> create() = 0;
//};
////手写一个苹果工厂类，继承父类
//class AppleFactory : public FruitFactory {
//public:
//	virtual std::shared_ptr<Fruit> create() {
//		return std::make_shared<Apple>();
//	}
//};
////手写一个香蕉工厂类，继承父类
//class BananaFactory : public FruitFactory {
//public:
//	virtual std::shared_ptr<Fruit> create() {
//		return std::make_shared<Banana>();
//	}
//};
//int main()
//{
//	//factory有使用多态
//	std::shared_ptr<FruitFactory> factory(new AppleFactory());
//	//fruit有使用多态
//	std::shared_ptr<Fruit> fruit;
//	fruit = factory->create();
//	fruit->show();
//	factory.reset(new BananaFactory());
//	fruit = factory->create();
//	fruit->show();
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <memory>
//
//class Fruit {
//public:
//	Fruit() {}
//	virtual void show() = 0;
//};
//class Apple : public Fruit {
//public:
//	Apple() {}
//	virtual void show() {
//		std::cout << "我是⼀个苹果" << std::endl;
//	}
//private:
//	std::string _color;
//};
//class Banana : public Fruit {
//public:
//	Banana() {}
//	virtual void show() {
//		std::cout << "我是⼀个⾹蕉" << std::endl;
//	}
//};
//class Animal {
//public:
//	virtual void voice() = 0;
//};
//class Lamp : public Animal {
//public:
//	void voice() { std::cout << "咩咩咩\n"; }
//};
//class Dog : public Animal {
//public:
//	void voice() { std::cout << "汪汪汪\n"; }
//};
//class Factory {
//public:
//	virtual std::shared_ptr<Fruit> getFruit(const std::string& name) = 0;
//	virtual std::shared_ptr<Animal> getAnimal(const std::string& name) = 0;
//};
//class FruitFactory : public Factory {
//public:
//	virtual std::shared_ptr<Animal> getAnimal(const std::string& name) {
//		return std::shared_ptr<Animal>();
//	}
//	virtual std::shared_ptr<Fruit> getFruit(const std::string& name) {
//		if (name == "苹果") {
//			return std::make_shared<Apple>();
//		}
//		else if (name == "⾹蕉") {
//			return std::make_shared<Banana>();
//		}
//		return std::shared_ptr<Fruit>();
//	}
//};
//class AnimalFactory : public Factory {
//
//public:
//	virtual std::shared_ptr<Fruit> getFruit(const std::string& name) {
//		return std::shared_ptr<Fruit>();
//	}
//	virtual std::shared_ptr<Animal> getAnimal(const std::string& name) {
//		if (name == "⼩⽺") {
//			return std::make_shared<Lamp>();
//		}
//		else if (name == "⼩狗") {
//			return std::make_shared<Dog>();
//		}
//		return std::shared_ptr<Animal>();
//	}
//};
//class FactoryProducer {
//public:
//	static std::shared_ptr<Factory> getFactory(const std::string& name) {
//		if (name == "动物") {
//			return std::make_shared<AnimalFactory>();
//		}
//		else {
//			return std::make_shared<FruitFactory>();
//		}
//	}
//};
//int main()
//{
//	std::shared_ptr<Factory> fruit_factory = FactoryProducer::getFactory("⽔果");
//	std::shared_ptr<Fruit> fruit = fruit_factory->getFruit("苹果");
//	fruit->show();
//	fruit = fruit_factory->getFruit("⾹蕉");
//	fruit->show();
//	std::shared_ptr<Factory> animal_factory = FactoryProducer::getFactory("动物");
//	std::shared_ptr<Animal> animal = animal_factory->getAnimal("⼩⽺");
//	animal->voice();
//	animal = animal_factory->getAnimal("⼩狗");
//	animal->voice();
//	return 0;
//}

//#include <iostream>
//#include <memory>
///*抽象电脑类*/
//class Computer {
//public:
//	using ptr = std::shared_ptr<Computer>;
//	Computer() {}
//	void setBoard(const std::string& board) { _board = board; }
//	void setDisplay(const std::string& display) { _display = display; }
//	virtual void setOs() = 0;
//	std::string toString() {
//		std::string computer = "Computer:{\n";
//		computer += "\tboard=" + _board + ",\n";
//		computer += "\tdisplay=" + _display + ",\n";
//		computer += "\tOs=" + _os + ",\n";
//		computer += "}\n";
//		return computer;
//	}
//protected:
//	std::string _board;
//	std::string _display;
//	std::string _os;
//};
///*具体产品类*/
//class MacBook : public Computer {
//public:
//	using ptr = std::shared_ptr<MacBook>;
//	MacBook() {}
//	virtual void setOs() {
//		_os = "Max Os X12";
//	}
//};
///*抽象建造者类：包含创建⼀个产品对象的各个部件的抽象接⼝*/
//class Builder {
//public:
//	using ptr = std::shared_ptr<Builder>;
//	virtual void buildBoard(const std::string& board) = 0;
//	virtual void buildDisplay(const std::string& display) = 0;
//	virtual void buildOs() = 0;
//	virtual Computer::ptr build() = 0;
//};
///*具体产品的具体建造者类：实现抽象接⼝，构建和组装各个部件*/
//class MacBookBuilder : public Builder {
//public:
//	using ptr = std::shared_ptr<MacBookBuilder>;
//	MacBookBuilder() : _computer(new MacBook()) {}
//	virtual void buildBoard(const std::string& board) {
//		_computer->setBoard(board);
//	}
//	virtual void buildDisplay(const std::string& display) {
//		_computer->setDisplay(display);
//	}
//	virtual void buildOs() {
//		_computer->setOs();
//	}
//	virtual Computer::ptr build() {
//		return _computer;
//	}
//private:
//	Computer::ptr _computer;
//};
///*指挥者类，提供给调⽤者使⽤，通过指挥者来构造复杂产品*/
//class Director {
//public:
//	Director(Builder* builder) :_builder(builder) {}
//	void construct(const std::string& board, const std::string& display) {
//		_builder->buildBoard(board);
//		_builder->buildDisplay(display);
//		_builder->buildOs();
//	}
//private:
//	Builder::ptr _builder;
//};
//int main()
//{
//	Builder* buidler = new MacBookBuilder();
//	std::unique_ptr<Director> pd(new Director(buidler));
//	pd->construct("英特尔主板", "VOC显⽰器");
//	Computer::ptr computer = buidler->build();
//	std::cout << computer->toString();
//	return 0;
//}
