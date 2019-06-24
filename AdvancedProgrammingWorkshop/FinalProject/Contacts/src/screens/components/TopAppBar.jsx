import React from 'react';
import { StyleSheet, View, StatusBar } from 'react-native';
import PropTypes from 'prop-types';
import Colors from '../common/Colors';

const styles = StyleSheet.create({
  header: {
    backgroundColor: Colors.primary,
    height: 56,
    alignItems: 'center',
    width: '100%',
    flexDirection: 'row',
    elevation: 6,
  },
});

const TopAppBar = ({ children }) => (
  <View>
    <StatusBar
      translucent
      animated
      backgroundColor="rgba(0, 0, 0, 0.3)"
      barStyle="light-content"
    />
    <View style={{ height: 24, backgroundColor: Colors.primary }} />
    <View style={styles.header}>
      {children}
    </View>
  </View>
);

TopAppBar.propTypes = {
  children: PropTypes.any.isRequired,
};

export default TopAppBar;
