
struct item
{
	item();
	char * name;
	int type;
};

class itemList
{
	public:
		itemList();
		~itemList();
		bool addItem(const &item);
		bool removeItem(const string name);
		bool findItem(string name) const;

	private:

};
