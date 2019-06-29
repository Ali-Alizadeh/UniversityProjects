import React from 'react';
import { StyleSheet, View, StatusBar } from 'react-native';
import PropTypes from 'prop-types';
import Colors from '../common/Colors';

const styles = StyleSheet.create({
  header: {
    backgroundColor: Colors.primary,
    height: 80,
    alignItems: 'center',
    width: '100%',
    flexDirection: 'row',
    elevation: 6,
    paddingTop: 24,
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
    <View style={styles.header}>
      {children}
    </View>
  </View>
);

TopAppBar.propTypes = {
  children: PropTypes.any.isRequired,
};

export default TopAppBar;
