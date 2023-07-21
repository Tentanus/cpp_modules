#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <info.hpp>

class Contact
{
  private:

	std::string first;
	std::string last;
	std::string nick;
	std::string phone;
	std::string secret;

	public:

	Contact();
	~Contact();

	void	set_first();
	void	set_last();
	void	set_nick();
	void	set_phone();
	void	set_secret();

	std::string	get_first() const;
	std::string	get_last() const;
	std::string	get_nick() const;
	std::string	get_phone() const;
	std::string	get_secret() const;

	void	print_contact();
};

#endif
