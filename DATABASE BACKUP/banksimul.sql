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
-- Table structure for table `accounts`
--

DROP TABLE IF EXISTS `accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accounts` (
  `account_id` int(11) NOT NULL AUTO_INCREMENT,
  `credit` int(11) DEFAULT '0',
  `iban` varchar(50) DEFAULT NULL,
  `balance` int(11) DEFAULT NULL,
  PRIMARY KEY (`account_id`),
  UNIQUE KEY `account_id_UNIQUE` (`account_id`),
  UNIQUE KEY `iban_UNIQUE` (`iban`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accounts`
--

LOCK TABLES `accounts` WRITE;
/*!40000 ALTER TABLE `accounts` DISABLE KEYS */;
INSERT INTO `accounts` VALUES (1,1,'FI4533410999152311',-399),(2,0,'FI4556433367977222',15789),(4,0,'FI 12 123456678',10000);
/*!40000 ALTER TABLE `accounts` ENABLE KEYS */;
UNLOCK TABLES;

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

--
-- Table structure for table `transfers`
--

DROP TABLE IF EXISTS `transfers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transfers` (
  `transfer_id` int(11) NOT NULL AUTO_INCREMENT,
  `action` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `amount` int(11) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `card_number` varchar(50) COLLATE utf8_bin DEFAULT NULL,
  `accounts_account_id` int(11) NOT NULL,
  PRIMARY KEY (`transfer_id`,`accounts_account_id`),
  UNIQUE KEY `transfer_id_UNIQUE` (`transfer_id`),
  KEY `fk_transfers_accounts1_idx` (`accounts_account_id`),
  CONSTRAINT `fk_transfers_accounts1` FOREIGN KEY (`accounts_account_id`) REFERENCES `accounts` (`account_id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=89 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transfers`
--

LOCK TABLES `transfers` WRITE;
/*!40000 ALTER TABLE `transfers` DISABLE KEYS */;
INSERT INTO `transfers` VALUES (1,'Withdraw',100,'2012-10-20 21:00:00','1234',1),(2,'Withdraw',20,'2022-04-25 16:05:36','05009BA52D',1),(3,'Withdraw',40,'2022-04-25 16:05:54','05009BA52D',1),(4,'Withdraw',100,'2012-10-20 21:00:00','123456789',2),(5,'Withdraw',60,'2022-04-25 16:06:05','05009BA52D',1),(6,'Withdraw',80,'2022-04-25 16:06:10','05009BA52D',1),(7,'Withdraw',100,'2022-04-25 16:06:12','05009BA52D',1),(8,'Withdraw',120,'2022-04-25 16:06:14','05009BA52D',1),(9,'Withdraw',140,'2022-04-25 16:06:16','05009BA52D',1),(10,'Withdraw',300,'2022-04-25 16:06:20','05009BA52D',1),(11,'Withdraw',100,'2012-10-20 21:00:00','123456789',2),(12,'Withdraw',20,'2022-04-26 10:02:39','06000649B0',1),(13,'Withdraw',80,'2022-04-26 10:16:37','05009BA52D',1),(14,'Withdraw',9,'2022-04-26 10:16:59','05009BA52D',1),(15,'Withdraw',20,'2022-04-26 10:19:04','05009BA52D',1),(16,'Withdraw',1,'2022-04-26 10:19:17','05009BA52D',1),(17,'Withdraw',40,'2022-04-26 16:01:28','06000649B0',1),(18,'Withdraw',40,'2022-04-26 16:02:45','05009BA52D',2),(19,'Withdraw',100,'2022-04-26 16:03:41','05009BA52D',2),(20,'Withdraw',9000,'2022-04-26 16:19:49','06000649B0',1),(21,'Withdraw',1600,'2022-04-26 16:20:07','06000649B0',1),(22,'Withdraw',20,'2022-04-26 16:22:03','06000649B0',1),(23,'Withdraw',50,'2022-04-26 16:29:32','06000649B0',1),(24,'Withdraw',60,'2022-04-26 16:30:22','05009BA52D',2),(25,'Withdraw',500,'2022-04-27 11:50:23','05009BA52D',2),(26,'Withdraw',20,'2022-04-27 12:37:03','05009BA52D',2),(27,'Withdraw',500,'2022-04-27 15:11:22','06000649B0',1),(28,'Withdraw',20,'2022-04-27 15:11:30','06000649B0',1),(29,'Withdraw',80,'2022-04-27 15:11:32','06000649B0',1),(30,'Withdraw',40,'2022-04-27 16:10:23','05009BA52D',2),(31,'Withdraw',0,'2022-04-27 16:10:27','05009BA52D',2),(32,'Withdraw',0,'2022-04-27 16:14:27','05009BA52D',2),(33,'Withdraw',20,'2022-04-27 16:15:47','05009BA52D',2),(34,'Withdraw',20,'2022-04-27 16:17:27','05009BA52D',2),(35,'Withdraw',80,'2022-04-27 16:18:10','05009BA52D',2),(36,'Withdraw',60,'2022-04-27 16:18:15','05009BA52D',2),(37,'Withdraw',20,'2022-04-27 17:43:45','05009BA52D',2),(38,'Withdraw',20,'2022-04-28 11:25:42','06000649B0',1),(39,'Withdraw',200,'2022-04-28 11:28:10','05009BA52D',2),(40,'Withdraw',100,'2022-04-28 14:39:09','05009BA52D',2),(41,'Withdraw',500,'2022-04-28 14:40:18','06000649B0',1),(42,'Withdraw',200,'2022-04-28 13:41:30','05009BA52D',2),(43,'Withdraw',200,'2022-04-28 13:41:30','06000649B0',1),(44,'Withdraw',200,'2022-04-28 14:05:06','05009BA52D',2),(45,'Deposit',200,'2022-04-28 14:05:06','FI45 3341 0999 1523 11',1),(46,'Withdraw',420,'2022-04-29 07:36:31','05009BA52D',2),(47,'Deposit',420,'2022-04-29 07:36:31','FI4533410999152311',1),(48,'Withdraw',80,'2022-04-29 07:39:27','05009BA52D',2),(49,'Deposit',80,'2022-04-29 07:39:27','FI4533410999152311',1),(50,'Withdraw',66,'2022-04-29 07:59:49','05009BA52D',2),(52,'Withdraw',4,'2022-04-29 08:02:17','05009BA52D',2),(53,'Deposit',4,'2022-04-29 08:02:17','FI4533410999152311',1),(54,'Withdraw',4,'2022-04-29 08:03:17','05009BA52D',2),(55,'Deposit',4,'2022-04-29 08:03:17','FI4533410999152311',1),(56,'Withdraw',16,'2022-04-29 08:13:30','FI12123456678',2),(57,'Deposit',16,'2022-04-29 08:13:30','FI4533410999152311',1),(58,'Hello',300,'2022-04-05 13:51:00','66',1),(59,'Withdraw',970,'2022-04-29 11:38:34','06000649B0',1),(60,'Withdraw',500,'2022-04-29 13:12:47','06000649B0',1),(61,'Withdraw',100,'2022-04-05 13:51:00','FI4556433367977222',2),(62,'Deposit',100,'2022-04-05 13:51:00','FI4533410999152311',1),(63,'Withdraw',110,'2022-04-29 14:59:02','FI4556433367977222',2),(64,'Deposit',110,'2022-04-29 14:59:02','FI4533410999152311',1),(65,'Withdraw',11,'2022-04-29 13:35:04','FI4533410999152311',1),(66,'Deposit',11,'2022-04-29 13:35:04','FI4556433367977222',2),(67,'Withdraw',99,'2022-04-29 15:38:42','FI4533410999152311',1),(68,'Deposit',99,'2022-04-29 15:38:42','FI4556433367977222',2),(69,'Withdraw',1,'2022-04-29 15:44:28','FI4556433367977222',2),(70,'Deposit',1,'2022-04-29 15:44:28','FI4556433367977222',2),(71,NULL,15000,'2012-10-20 21:00:00','123456789',1),(72,NULL,15000,'2012-10-20 21:00:00','123456',1),(73,NULL,3,'2012-10-20 21:00:00','123456',1),(74,'Withdraw',20,'2022-05-02 08:33:52','05009BA52D',2),(75,'Withdraw',100,'2022-05-02 09:08:23','FI4533410999152311',1),(76,'Deposit',100,'2022-05-02 09:08:23','FI4556433367977222',2),(77,'Withdraw',1480,'2022-05-02 10:29:13','05009BA52D',2),(78,'Withdraw',0,'2022-05-02 10:55:14','06000649B0',1),(79,'Withdraw',20,'2022-05-02 10:58:46','06000649B0',1),(80,'Withdraw',200,'2022-05-02 10:59:31','06000649B0',1),(81,'Withdraw',80,'2022-05-02 11:01:34','06000649B0',1),(82,'Withdraw',9999,'2022-05-02 11:02:06','FI4533410999152311',1),(83,'Deposit',9999,'2022-05-02 11:02:06','FI4556433367977222',2),(84,'Withdraw',40,'2022-05-02 11:10:38','05009BA52D',2),(85,'Withdraw',200,'2022-05-02 11:11:42','05009BA52D',2),(86,'Withdraw',80,'2022-05-02 11:11:49','05009BA52D',2),(87,'Withdraw',40,'2022-05-02 11:11:52','05009BA52D',2),(88,'Withdraw',60,'2022-05-02 11:11:53','05009BA52D',2);
/*!40000 ALTER TABLE `transfers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `fname` varchar(24) COLLATE utf8_bin DEFAULT NULL,
  `lname` varchar(50) COLLATE utf8_bin DEFAULT NULL,
  `address` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `phone` varchar(24) COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `user_id_UNIQUE` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'Johannes','Rantapää','Yliopistokatu 46','0401990455'),(3,'Joona','Martinkauppi','Osoite 1','050 1234567'),(4,'Testi','Ukko','OAMK kellari','0441123456');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users_has_accounts`
--

DROP TABLE IF EXISTS `users_has_accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users_has_accounts` (
  `users_user_id` int(11) NOT NULL,
  `accounts_account_id` int(11) NOT NULL,
  PRIMARY KEY (`users_user_id`,`accounts_account_id`),
  KEY `fk_users_has_accounts_accounts1_idx` (`accounts_account_id`),
  CONSTRAINT `fk_users_has_accounts_accounts1` FOREIGN KEY (`accounts_account_id`) REFERENCES `accounts` (`account_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_users_has_accounts_users1` FOREIGN KEY (`users_user_id`) REFERENCES `users` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users_has_accounts`
--

LOCK TABLES `users_has_accounts` WRITE;
/*!40000 ALTER TABLE `users_has_accounts` DISABLE KEYS */;
INSERT INTO `users_has_accounts` VALUES (1,1),(3,2);
/*!40000 ALTER TABLE `users_has_accounts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'sql11488057'
--
/*!50003 DROP PROCEDURE IF EXISTS `credit_transfer` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
CREATE DEFINER=`sql11488057`@`%` PROCEDURE `credit_transfer`(IN pSenderIban VARCHAR(50), IN pRecvIban VARCHAR(50), IN pAmount DOUBLE, IN pDate VARCHAR(50))
BEGIN
  DECLARE test1, test2, pSenderId, pRecvId INT DEFAULT 0;
  set @pSenderId = (select account_id from accounts where iban=pSenderIban); #Sender account_id
  set @pRecvId = (select account_id from accounts where iban=pRecvIban); #Receiver account_id
  START TRANSACTION;
  UPDATE accounts SET balance=balance-pAmount WHERE account_id=@pSenderId;
  SET test1=ROW_COUNT();
  UPDATE accounts SET balance=balance+pAmount WHERE account_id=@pRecvId;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN
      COMMIT;
      INSERT INTO transfers(transfers.amount,transfers.action,transfers.date,transfers.card_number,transfers.accounts_account_id) VALUES(pAmount,"Withdraw",pDate,pSenderIban,@pSenderId);
      INSERT INTO transfers(transfers.amount,transfers.action,transfers.date,transfers.card_number,transfers.accounts_account_id) VALUES(pAmount,"Deposit",pDate,pRecvIban,@pRecvId);
    ELSE
      ROLLBACK;
  END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_transfer` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
CREATE DEFINER=`sql11488057`@`%` PROCEDURE `debit_transfer`(IN pSenderIban VARCHAR(50), IN pRecvIban VARCHAR(50), IN pAmount DOUBLE, IN pDate VARCHAR(50))
BEGIN
  DECLARE test1, test2, pSenderId, pRecvId INT DEFAULT 0;
  set @pSenderId = (select account_id from accounts where iban=pSenderIban); #Sender account_id
  set @pRecvId = (select account_id from accounts where iban=pRecvIban); #Receiver account_id
  START TRANSACTION;
  UPDATE accounts SET balance=balance-pAmount WHERE account_id=@pSenderId AND balance>=pAmount;
  SET test1=ROW_COUNT();
  UPDATE accounts SET balance=balance+pAmount WHERE account_id=@pRecvId;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN
      COMMIT;
      INSERT INTO transfers(transfers.amount,transfers.action,transfers.date,transfers.card_number,transfers.accounts_account_id) VALUES(pAmount,"Withdraw",pDate,pSenderIban,@pSenderId);
      INSERT INTO transfers(transfers.amount,transfers.action,transfers.date,transfers.card_number,transfers.accounts_account_id) VALUES(pAmount,"Deposit",pDate,pRecvIban,@pRecvId);
    ELSE
      ROLLBACK;
  END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `getBySelectedDate` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
CREATE DEFINER=`sql11488057`@`%` PROCEDURE `getBySelectedDate`(IN num INT, IN pDate VARCHAR(50))
BEGIN
select transfer_id, action, amount, date_format(date, "%d-%m-%Y %H:%i:%s") as date, card_number, accounts_account_id from transfers WHERE date_format(date, "%d-%m-%Y %H:%i:%s") like concat(pDate,'%') AND accounts_account_id=num;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `getInfo` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
CREATE DEFINER=`sql11488057`@`%` PROCEDURE `getInfo`(IN pCardNum VARCHAR(50))
BEGIN
DECLARE tAccountId, tUserId, tLocked, tCredit INT DEFAULT 0;
DECLARE tIban, tName VARCHAR(50) DEFAULT 0;
SET @tAccountId := (SELECT accounts_account_id FROM cards WHERE card_number=pCardNum);
SET @tUserId := (SELECT users_user_id FROM cards WHERE card_number=pCardNum);
SET @tLocked := (SELECT locked FROM cards WHERE card_number=pCardNum);
SET @tCredit := (SELECT credit FROM accounts WHERE account_id=@tAccountId);
SET @tIban := (SELECT iban FROM accounts WHERE account_id=@tAccountId);
SET @tName := (SELECT concat(fname," ",lname) as fullname FROM users WHERE user_id=@tUserId);
SELECT @tName AS fullname, @tIban AS iban, @tUserId AS user_id, @tAccountId as account_id, @tLocked AS locked, @tCredit AS credit;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `getNextAndPrevTransfers` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
CREATE DEFINER=`sql11488057`@`%` PROCEDURE `getNextAndPrevTransfers`(IN id int, IN bot int, IN top int)
BEGIN
SELECT * FROM (SELECT transfer_id, action, amount, date_format(DATE, "%d.%m.%y, %h:%m:%s") AS date, card_number, accounts_account_id FROM transfers 
WHERE accounts_account_id=id AND transfer_id BETWEEN bot AND top ORDER BY transfer_id DESC) sub ORDER BY transfer_id ASC;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `getUserInfo` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = '' */ ;
DELIMITER ;;
CREATE DEFINER=`sql11488057`@`%` PROCEDURE `getUserInfo`(IN pCardNum VARCHAR(50))
BEGIN
DECLARE tAccountId, tUserId, tLocked, tCredit, tBalance INT DEFAULT 0;
DECLARE tIban, tName VARCHAR(50) DEFAULT 0;
SET @tAccountId := (SELECT accounts_account_id FROM cards WHERE card_number=pCardNum);
SET @tUserId := (SELECT users_user_id FROM cards WHERE card_number=pCardNum);
SET @tLocked := (SELECT locked FROM cards WHERE card_number=pCardNum);
SET @tCredit := (SELECT credit FROM accounts WHERE account_id=@tAccountId);
SET @tIban := (SELECT iban FROM accounts WHERE account_id=@tAccountId);
SET @tName := (SELECT concat(fname," ",lname) AS fullname FROM users WHERE user_id=@tUserId);
SET @tBalance := (SELECT balance FROM accounts WHERE account_id=@tAccountId);
SELECT @tName AS fullname, @tIban AS iban, @tBalance AS balance, @tUserId AS user_id, @tAccountId as account_id, @tLocked AS locked, @tCredit AS credit;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-02 11:36:48
