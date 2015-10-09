Container::Container()
{	
	this->value = -1;
	this->flag = false;
}

Container::Container(bool f, int val)
{
	this->flag = f;
	this->value = val;
}

void Container::setValue(int x)
{
	this->value = x;
}

int Container::getValue()
{
	return this->value;
}