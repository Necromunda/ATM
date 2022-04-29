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
SELECT * FROM (SELECT transfer_id, action, amount, date_format(DATE, "%d.%m.%y, %h:%m:%s") AS DATE, card_number, accounts_account_id FROM transfers 
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
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-04-29 16:31:27
