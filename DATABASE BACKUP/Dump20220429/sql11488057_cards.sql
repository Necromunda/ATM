CREATE DATABASE  IF NOT EXISTS `sql11488057` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `sql11488057`;
-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: sql11.freemysqlhosting.net    Database: sql11488057
-- ------------------------------------------------------
-- Server version	5.5.62-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `cards`
--

DROP TABLE IF EXISTS `cards`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cards` (
  `card_number` varchar(50) COLLATE utf8_bin NOT NULL,
  `pin_code` varchar(255) COLLATE utf8_bin DEFAULT NULL,
  `locked` tinyint(4) NOT NULL,
  `accounts_account_id` int(11) NOT NULL,
  `users_user_id` int(11) NOT NULL,
  UNIQUE KEY `card_number_UNIQUE` (`card_number`),
  KEY `fk_cards_accounts1_idx` (`accounts_account_id`),
  KEY `fk_cards_users1_idx` (`users_user_id`),
  CONSTRAINT `fk_cards_accounts1` FOREIGN KEY (`accounts_account_id`) REFERENCES `accounts` (`account_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_cards_users1` FOREIGN KEY (`users_user_id`) REFERENCES `users` (`user_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cards`
--

LOCK TABLES `cards` WRITE;
/*!40000 ALTER TABLE `cards` DISABLE KEYS */;
INSERT INTO `cards` VALUES ('05009BA52D','$2a$10$/xGwnxK5GGuEoKJdwKftAeDARsRW9HTPKi73XhCsR5moptb2wdHaW',0,2,1),('06000649B0','$2a$10$hkMGDSm5gTxrZzjHrJqexOowmpDHwcWLiDIuQVD11LYFCrAdnqO3W',0,1,4),('123456','$2a$10$vgcBqoplvH.AQiudSJfEieGIEZV6kW4GZsLz0Ny1yJgJViB/NV4eq',0,1,1),('123456789','$2a$10$S9XhzZNuzlGhadBYJ4mAFOVAD.FaWkLNM2Ey5m.dM.231xT3mhW.2',0,2,3);
/*!40000 ALTER TABLE `cards` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-04-29 16:31:25
