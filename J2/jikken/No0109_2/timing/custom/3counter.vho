-- Copyright (C) 1991-2008 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II"
-- VERSION "Version 8.1 Build 163 10/28/2008 SJ Web Edition"

-- DATE "01/29/2018 17:40:48"

-- 
-- Device: Altera EP2S15F484C3 Package FBGA484
-- 

-- 
-- This VHDL file should be used for Custom VHDL only
-- 

LIBRARY IEEE, stratixii;
USE IEEE.std_logic_1164.all;
USE stratixii.stratixii_components.all;

ENTITY 	\3counter\ IS
    PORT (
	Q0 : OUT std_logic;
	VCC : IN std_logic;
	CLK : IN std_logic;
	Q1 : OUT std_logic;
	Q2 : OUT std_logic
	);
END \3counter\;

ARCHITECTURE structure OF \3counter\ IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Q0 : std_logic;
SIGNAL ww_VCC : std_logic;
SIGNAL ww_CLK : std_logic;
SIGNAL ww_Q1 : std_logic;
SIGNAL ww_Q2 : std_logic;
SIGNAL \CLK~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLK~combout\ : std_logic;
SIGNAL \CLK~clkctrl_outclk\ : std_logic;
SIGNAL \VCC~combout\ : std_logic;
SIGNAL \inst8~21DUPLICATE_combout\ : std_logic;
SIGNAL \inst8~DUPLICATE_regout\ : std_logic;
SIGNAL \inst7~55_combout\ : std_logic;
SIGNAL \inst7~regout\ : std_logic;
SIGNAL \inst~62_combout\ : std_logic;
SIGNAL \inst~regout\ : std_logic;
SIGNAL \inst8~21_combout\ : std_logic;
SIGNAL \inst8~regout\ : std_logic;
SIGNAL \inst~62DUPLICATE_combout\ : std_logic;
SIGNAL \inst~DUPLICATE_regout\ : std_logic;
SIGNAL \ALT_INV_inst~regout\ : std_logic;
SIGNAL \ALT_INV_inst7~regout\ : std_logic;
SIGNAL \ALT_INV_inst8~regout\ : std_logic;
SIGNAL \ALT_INV_VCC~combout\ : std_logic;
SIGNAL \ALT_INV_CLK~clkctrl_outclk\ : std_logic;
SIGNAL \ALT_INV_inst~DUPLICATE_regout\ : std_logic;
SIGNAL \ALT_INV_inst8~DUPLICATE_regout\ : std_logic;

BEGIN

Q0 <= ww_Q0;
ww_VCC <= VCC;
ww_CLK <= CLK;
Q1 <= ww_Q1;
Q2 <= ww_Q2;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\CLK~clkctrl_INCLK_bus\ <= (gnd & gnd & gnd & \CLK~combout\);
\ALT_INV_inst~regout\ <= NOT \inst~regout\;
\ALT_INV_inst7~regout\ <= NOT \inst7~regout\;
\ALT_INV_inst8~regout\ <= NOT \inst8~regout\;
\ALT_INV_VCC~combout\ <= NOT \VCC~combout\;
\ALT_INV_CLK~clkctrl_outclk\ <= NOT \CLK~clkctrl_outclk\;
\ALT_INV_inst~DUPLICATE_regout\ <= NOT \inst~DUPLICATE_regout\;
\ALT_INV_inst8~DUPLICATE_regout\ <= NOT \inst8~DUPLICATE_regout\;

\CLK~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_CLK,
	combout => \CLK~combout\);

\CLK~clkctrl\ : stratixii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock")
-- pragma translate_on
PORT MAP (
	inclk => \CLK~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLK~clkctrl_outclk\);

\VCC~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_VCC,
	combout => \VCC~combout\);

\inst8~21DUPLICATE\ : stratixii_lcell_comb
-- Equation(s):
-- \inst8~21DUPLICATE_combout\ = !\inst8~DUPLICATE_regout\ & \inst7~regout\ & ( \inst~regout\ ) # \inst8~DUPLICATE_regout\ & !\inst7~regout\

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111111111111111100001111000011110000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_inst~regout\,
	datae => \ALT_INV_inst8~DUPLICATE_regout\,
	dataf => \ALT_INV_inst7~regout\,
	combout => \inst8~21DUPLICATE_combout\);

\inst8~DUPLICATE\ : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst8~21DUPLICATE_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst8~DUPLICATE_regout\);

\inst7~55\ : stratixii_lcell_comb
-- Equation(s):
-- \inst7~55_combout\ = \inst7~regout\ & \inst~regout\ & ( \inst8~DUPLICATE_regout\ ) # !\inst7~regout\ & \inst~regout\ # \inst7~regout\ & !\inst~regout\ & ( !\inst8~DUPLICATE_regout\ )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111100001111000011111111111111110000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_inst8~DUPLICATE_regout\,
	datae => \ALT_INV_inst7~regout\,
	dataf => \ALT_INV_inst~regout\,
	combout => \inst7~55_combout\);

inst7 : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst7~55_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst7~regout\);

\inst~62\ : stratixii_lcell_comb
-- Equation(s):
-- \inst~62_combout\ = \inst~regout\ & \inst7~regout\ & ( !\VCC~combout\ ) # !\inst~regout\ & \inst7~regout\ & ( !\inst8~regout\ ) # \inst~regout\ & !\inst7~regout\ & ( !\VCC~combout\ ) # !\inst~regout\ & !\inst7~regout\

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111111111111111111100001111000011111111000000001111000011110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_VCC~combout\,
	datad => \ALT_INV_inst8~regout\,
	datae => \ALT_INV_inst~regout\,
	dataf => \ALT_INV_inst7~regout\,
	combout => \inst~62_combout\);

inst : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst~62_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst~regout\);

\inst8~21\ : stratixii_lcell_comb
-- Equation(s):
-- \inst8~21_combout\ = !\inst8~regout\ & \inst7~regout\ & ( \inst~regout\ ) # \inst8~regout\ & !\inst7~regout\

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111111111111111100000000111111110000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datad => \ALT_INV_inst~regout\,
	datae => \ALT_INV_inst8~regout\,
	dataf => \ALT_INV_inst7~regout\,
	combout => \inst8~21_combout\);

inst8 : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst8~21_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst8~regout\);

\inst~62DUPLICATE\ : stratixii_lcell_comb
-- Equation(s):
-- \inst~62DUPLICATE_combout\ = \inst~DUPLICATE_regout\ & \inst7~regout\ & ( !\VCC~combout\ ) # !\inst~DUPLICATE_regout\ & \inst7~regout\ & ( !\inst8~regout\ ) # \inst~DUPLICATE_regout\ & !\inst7~regout\ & ( !\VCC~combout\ ) # !\inst~DUPLICATE_regout\ & 
-- !\inst7~regout\

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111111111111111111111110000000011110000111100001111111100000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_inst8~regout\,
	datad => \ALT_INV_VCC~combout\,
	datae => \ALT_INV_inst~DUPLICATE_regout\,
	dataf => \ALT_INV_inst7~regout\,
	combout => \inst~62DUPLICATE_combout\);

\inst~DUPLICATE\ : stratixii_lcell_ff
PORT MAP (
	clk => \ALT_INV_CLK~clkctrl_outclk\,
	datain => \inst~62DUPLICATE_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \inst~DUPLICATE_regout\);

\Q0~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	datain => \inst~DUPLICATE_regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_Q0);

\Q1~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	datain => \inst7~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_Q1);

\Q2~I\ : stratixii_io
-- pragma translate_off
GENERIC MAP (
	ddio_mode => "none",
	ddioinclk_input => "negated_inclk",
	dqs_delay_buffer_mode => "none",
	dqs_out_mode => "none",
	inclk_input => "normal",
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none",
	sim_dqs_delay_increment => 0,
	sim_dqs_intrinsic_delay => 0,
	sim_dqs_offset_increment => 0)
-- pragma translate_on
PORT MAP (
	datain => \inst8~DUPLICATE_regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_Q2);
END structure;


