#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../book.hpp"
#include "../node.hpp"
#include "../tree.hpp"
#include "../book_loader.hpp"
#include <string>

const std::string TITLE     = "The Wave";
const std::string AUTHOR    = "Krazy George";
const std::string SUBJECT   = "Being awesome";
const std::string FORMAT    = "Kindle";
const std::string PUBLISHER = "Some Lucky Duck";
const int NUMBER_AVAILABLE  = 0;

TEST_CASE ("Book creation and checkout/in")
{
	Book b(TITLE, AUTHOR, SUBJECT, FORMAT, PUBLISHER, NUMBER_AVAILABLE);
	REQUIRE(TITLE == b.GetTitle());

	REQUIRE(!b.Checkout()); // since initially there are 0 copies
	REQUIRE(b.Checkin()); // put one copy back
	REQUIRE(b.Checkout()); // now can check out
	Book a(TITLE, "Foo", "Foo", "Foo", "Foo", 1000);
	REQUIRE(a == b); // even though all details differ, our == check is based only on the title

	Book c("Aardvarks are Early in the Alphabet", AUTHOR, SUBJECT, FORMAT, PUBLISHER, NUMBER_AVAILABLE);
	REQUIRE(c < a); // we need at least one comparison in order to support sorting Boo
}

TEST_CASE("Node test")
{
	Book* b1 = new Book("A", AUTHOR, SUBJECT, FORMAT, PUBLISHER,NUMBER_AVAILABLE);
	Node<Book>* n1 = new Node<Book>(b1);
	REQUIRE(n1->GetValue()->GetTitle() == "A");

	Book* b2 = new Book("B", AUTHOR, SUBJECT, FORMAT, PUBLISHER,NUMBER_AVAILABLE);
	Node<Book>* n2 = new Node<Book>(b2);
	n2->SetLeft(n1);
	REQUIRE(n2->GetLeft()->GetValue()->GetTitle() == "A");

	Book* b3 = new Book("C", AUTHOR, SUBJECT, FORMAT, PUBLISHER, NUMBER_AVAILABLE);
	Node<Book>* n3 = new Node<Book>(b3);
	n2->SetRight(n3);
	REQUIRE(n2->GetRight()->GetValue()->GetTitle() == "C");

	delete n1;
	delete n2;
	delete n3;
}

TEST_CASE ("Tree test")
{
	Tree<Book> library;

	library.Insert(new Book("B", "AUTHOR B", "SUBJECT B", "FORMAT B", "PUBLISHER B", 1));
	library.Insert(new Book("A", "AUTHOR A", "SUBJECT A", "FORMAT A", "PUBLISHER A", 0));
	library.Insert(new Book("C", "AUTHOR C", "SUBJECT C", "FORMAT C", "PUBLISHER C", 2));

	const std::string abcTree = "A, by AUTHOR A"
		"\n\tSubject: SUBJECT A"
		"\n\tPublisher: PUBLISHER A"
		"\n\t0 FORMAT A copies available"
		"\nB, by AUTHOR B"
		"\n\tSubject: SUBJECT B"
		"\n\tPublisher: PUBLISHER B"
		"\n\t1 FORMAT B copies available"
		"\nC, by AUTHOR C"
		"\n\tSubject: SUBJECT C"
		"\n\tPublisher: PUBLISHER C"
		"\n\t2 FORMAT C copies available\n";
	REQUIRE(abcTree == library.Traverse());

	const std::string abcTreeTitles = "A\nB\nC\n";
	const bool showFullDetails = false;
	REQUIRE(abcTreeTitles == library.Traverse(showFullDetails));

	Node<Book>* cBook = library.Search("C");
	REQUIRE("C" == cBook->GetValue()->GetTitle());

	Node<Book>* dBook = library.Search("D");
	REQUIRE(nullptr == dBook);
}

TEST_CASE ("Book Loader")
{
	BookLoader parser;
	REQUIRE(!parser.SetFileName("zzzzzzzz"));
	REQUIRE(parser.SetFileName("book_data.txt"));

	Book* b = parser.GetNextBook();
	REQUIRE("Artificial Intelligence" == b->GetTitle());
	delete b;

	b = parser.GetNextBook();
	REQUIRE("Computer Networking" == b->GetTitle());
	delete b;
	
	do
	{
		b = parser.GetNextBook();
		if (b != nullptr)
		{
			delete b;
		}
	} while (b != nullptr);

	REQUIRE(nullptr == parser.GetNextBook());
}
