-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: 
-- Версия на сървъра: 10.1.21-MariaDB
-- PHP Version: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `wapi_book_library`
--

-- --------------------------------------------------------

--
-- Структура на таблица `books`
--

CREATE TABLE `books` (
  `book_id` int(11) NOT NULL,
  `book_title` varchar(250) NOT NULL,
  `author` varchar(100) NOT NULL,
  `page_count` int(11) NOT NULL,
  `publish_date` date NOT NULL DEFAULT '0000-00-00',
  `book_format` varchar(2) NOT NULL,
  `isbn` varchar(60) NOT NULL,
  `resume` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Схема на данните от таблица `books`
--

INSERT INTO `books` (`book_id`, `book_title`, `author`, `page_count`, `publish_date`, `book_format`, `isbn`, `resume`) VALUES
(1, 'Little Red Riding Hood', 'Charles Perrault', 20, '1881-06-21', 'A4', '978-3-16-148410-0', '\"Little Red Riding Hood\", or \"Little Red Ridinghood\", also known as \"Little Red Cap\" or simply \"Red Riding Hood\", is a European fairy tale about a young girl and a Big Bad Wolf.'),
(2, 'The Emperor\'s New Clothes', 'Hans Christian Andersen', 100, '2017-06-22', 'A3', '1234567', 'rerererre'),
(4, 'Mary Poppins', 'Pamela Travers', 120, '1933-06-22', 'A4', '1234567890', 'A quintessential English nanny, Mary Poppins is a slightly stern but caring woman, who uses magic and self-control to take care of the Banks children. She is usually identifiable by her sensible hat and parrot umbrella which she brings with her wherever she goes on outings. She is kind towards the children, but can be firm when needed. She is practically perfect in every way.'),
(6, 'Cinderella', 'Jacob and Wilhelm Grimm', 120, '2017-06-14', 'A4', '1234567', 'dffgfhghhjh'),
(7, 'The Great Alone', 'Kristin Hannah', 345, '2018-02-06', 'A4', '000000001', 'A Novel Hardcover'),
(10, 'Educated', 'Tara Westover', 500, '2018-02-07', 'A4', '000000002', 'A Memoir Hardcover'),
(11, 'The Hazel Wood', 'Melissa Albert', 523, '2018-02-01', 'A4', '000000003', 'A Novel Hardcover'),
(12, 'Call Me Zebra', 'Azareen Van der Vliet Oloomi', 600, '2018-02-12', 'A4', '000000006', 'Visit Amazon\\\'s Azareen Van der Vliet Oloomi Page'),
(13, 'The Line Becomes a River', 'Francisco Cantu', 800, '2018-02-19', 'A4', '000000007', 'Visit Amazon\\\'s Francisco CantÃº Page'),
(14, 'Force of Nature', 'Jane Harper', 567, '0000-00-00', 'A4', '000000009', 'Visit Amazon\\\'s Jane Harper Page'),
(16, 'Only Killers and Thieves', 'Paul Howarth', 676, '2018-02-12', 'A4', '000000010', 'Visit Amazon\\\'s Paul Howarth Page'),
(17, 'The Monk of Mokha', 'Dave Eggers', 987, '2018-02-24', 'A4', '000000011', 'Visit Amazon\\\'s Dave Eggers Page'),
(18, 'Freshwater', 'Akwaeke Emezi', 360, '2018-02-13', 'A4', '0000000012', 'Visit Amazon\\\'s Akwaeke Emezi Page'),
(25, 'A Tree Grows in Brooklyn', ' Betty Smith', 600, '2014-09-16', 'A4', '0000000012', 'A Novel'),
(30, 'Around the World in 50 Ways', 'Lonely Planet Kids', 300, '2018-02-25', 'A4', '000000020', 'Visit Amazon\\\'s Lonely Planet Kids Page'),
(31, 'The Bee Book', 'Charlotte Milner', 200, '2018-02-06', 'A4', '000000021', 'Visit Amazon\\\'s Charlotte Milner Page');

-- --------------------------------------------------------

--
-- Структура на таблица `users`
--

CREATE TABLE `users` (
  `user_id` int(11) NOT NULL,
  `username` varchar(50) NOT NULL,
  `pass` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Схема на данните от таблица `users`
--

INSERT INTO `users` (`user_id`, `username`, `pass`) VALUES
(1, 'ivan_ivanov', '123456'),
(2, 'peter_petrov', '123456');

-- --------------------------------------------------------

--
-- Структура на таблица `users_books`
--

CREATE TABLE `users_books` (
  `user_id` int(11) NOT NULL,
  `book_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Схема на данните от таблица `users_books`
--

INSERT INTO `users_books` (`user_id`, `book_id`) VALUES
(1, 1),
(1, 2),
(1, 25),
(1, 30),
(2, 4),
(2, 6),
(2, 7),
(2, 10),
(2, 11),
(2, 12),
(2, 13),
(2, 14),
(2, 16),
(2, 17),
(2, 18),
(2, 31);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`book_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`user_id`);

--
-- Indexes for table `users_books`
--
ALTER TABLE `users_books`
  ADD PRIMARY KEY (`user_id`,`book_id`),
  ADD KEY `fk_book_id` (`book_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `books`
--
ALTER TABLE `books`
  MODIFY `book_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `user_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- Ограничения за дъмпнати таблици
--

--
-- Ограничения за таблица `users_books`
--
ALTER TABLE `users_books`
  ADD CONSTRAINT `fk_book_id` FOREIGN KEY (`book_id`) REFERENCES `books` (`book_id`),
  ADD CONSTRAINT `fk_user_id` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
