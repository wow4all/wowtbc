/*
Navicat MySQL Data Transfer

Source Server         : 2.4
Source Server Version : 50045
Source Host           : localhost:3306
Source Database       : tbcwowfunserverloginandcharacter

Target Server Type    : MYSQL
Target Server Version : 50045
File Encoding         : 65001

Date: 2012-03-04 19:50:05
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `worldstate_save_data`
-- ----------------------------
DROP TABLE IF EXISTS `worldstate_save_data`;
CREATE TABLE `worldstate_save_data` (
  `setting_id` varchar(50) NOT NULL,
  `setting_value` varchar(200) NOT NULL,
  PRIMARY KEY  (`setting_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of worldstate_save_data
-- ----------------------------
INSERT INTO `worldstate_save_data` VALUES ('hellfire-overlook-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('hellfire-brokenhill-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('hellfire-stadium-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('Terokkar-Tower2-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('Terokkar-Tower3-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('Terokkar-Tower4-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('Terokkar-Tower5-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('Terokkar-Tower1-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('Zangarmarsh-TowerEast-status', '1');
INSERT INTO `worldstate_save_data` VALUES ('Zangarmarsh-TowerWest-status', '1');
