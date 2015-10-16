CContainer::CContainer()
{	
	this->value = -1;
	this->flag = false;
}

CContainer::CContainer(bool f, long int val)
{
	this->flag = f;
	this->value = val;
}

void CContainer::setValue(long int x)
{
	this->value = x;
}

long int CContainer::getValue()
{
	return this->value;
}